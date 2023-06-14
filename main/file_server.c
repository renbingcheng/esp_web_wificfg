#include <stdio.h>
#include <string.h>
#include <sys/param.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#include "esp_err.h"
#include "esp_log.h"

#include "esp_vfs.h"
#include "esp_spiffs.h"
#include "esp_http_server.h"

#include "cJSON.h"

#define FILE_PATH_MAX (ESP_VFS_PATH_MAX + CONFIG_SPIFFS_OBJ_NAME_LEN)
#define MAX_FILE_SIZE   (200*1024)
#define MAX_FILE_SIZE_STR "200KB"
#define SCRATCH_BUFSIZE  8192

extern unsigned char wifi_ssid[32];
extern unsigned char wifi_password[64];

struct file_server_data {
    char base_path[ESP_VFS_PATH_MAX + 1];
    char scratch[SCRATCH_BUFSIZE];
};

static const char *TAG = "file_server";

static esp_err_t send_wifi_handler(httpd_req_t *req)
{
    char buf[128];
    int ret, remaining = req->content_len;
    bzero(buf, sizeof(buf));

    while (remaining > 0) {
        ret = httpd_req_recv(req, buf, MIN(remaining, sizeof(buf)));
        if (ret <= 0) {
            if (ret == HTTPD_SOCK_ERR_TIMEOUT) {
                continue;
            }
            return ESP_FAIL;
        }
        remaining -= ret;
    }

     cJSON *root = cJSON_Parse(buf);
    //  int ssid = cJSON_GetObjectItem(root, "wifi_name")->valueint;
    //  int code = cJSON_GetObjectItem(root, "wifi_code")->valueint;

     char *ssid = cJSON_GetObjectItem(root, "wifi_name")->valuestring;
     char *code = cJSON_GetObjectItem(root, "wifi_code")->valuestring;
     int len1 = strlen(ssid);
     int len2 = strlen(code);
     memcpy(wifi_ssid,ssid,strlen(ssid));
     memcpy(wifi_password,code,strlen(code));
     wifi_ssid[len1] = '\0';
     wifi_password[len2] = '\0';
     cJSON_Delete(root);
    //  ESP_LOGI(TAG, "json load  finished. SSID:%d password:%d ",ssid,code);
    // ESP_LOGI(TAG, "json load  finished. SSID:%s password:%s ",wifi_ssid,wifi_password);
    printf("\r\nwifi_ssid:");
    for(int i = 0;i<len1;i++){
        printf("%c",wifi_ssid[i]);
    }

    printf("\r\nwifi_code:");
    for(int i = 0;i<len2;i++){
        printf("%c",wifi_password[i]);
    }
    printf("\r\n");
    httpd_resp_sendstr(req, "Post control value successfully");
    return ESP_OK;
}

static esp_err_t root_get_handler(httpd_req_t *req)
{
    extern const unsigned char upload_script_start[] asm("_binary_upload_script_html_start");
    extern const unsigned char upload_script_end[] asm("_binary_upload_script_html_end");
    const size_t upload_script_size = (upload_script_end - upload_script_start);
    httpd_resp_send(req, (const char *)upload_script_start, upload_script_size);
    return ESP_OK;
}

esp_err_t start_file_server()
{
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    ESP_LOGI(TAG, "Starting HTTP Server");
    if (httpd_start(&server, &config) != ESP_OK) {
        ESP_LOGE(TAG, "Failed to start file server!");
        return ESP_FAIL;
    }

    httpd_uri_t wifi_data = {
        .uri       = "/wifi_data",
        .method    = HTTP_POST,
        .handler   = send_wifi_handler,
        .user_ctx  = NULL
    };
    httpd_register_uri_handler(server, &wifi_data);

    httpd_uri_t root = {
        .uri       = "/",
        .method    = HTTP_GET,
        .handler   = root_get_handler,
        .user_ctx  = NULL
    };
    httpd_register_uri_handler(server, &root);

    return ESP_OK;
}
