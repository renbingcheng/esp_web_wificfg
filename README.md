# README: ESP32C3 Web Server for WiFi Configuration

## 概述 - Overview

本 README 提供了使用 ESP-IDF 框架提供的代码，在 ESP32C3 上创建一个用于配置 WiFi 参数的 Web 服务器的指南。此代码允许您设置一个 Web 页面，用户可以在其中输入 ESP32C3 连接到 WiFi 网络所需的 WiFi SSID 和密码。

This README provides instructions on how to use the provided code with ESP-IDF framework to create a web server on ESP32C3 for configuring WiFi parameters. This code allows you to set up a web page where users can input the WiFi SSID and password required for ESP32C3 to connect to a WiFi network.

## 先决条件 - Prerequisites

在开始之前，请确保满足以下先决条件：

Before you begin, make sure you have the following prerequisites in place:

1. [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/get-started/index.html) 开发环境已设置好。

   - ESP-IDF development environment is set up.

2. 对 ESP-IDF 和 ESP32C3 有基本了解。

   - Basic knowledge of ESP-IDF and ESP32C3.

## 入门 - Getting Started

1. 将提供的代码复制到您的 ESP-IDF 项目目录中或创建一个新的 ESP-IDF 项目。

   - Copy the provided code into your ESP-IDF project directory or create a new ESP-IDF project.

2. 修改代码中的以下变量以匹配您的 WiFi 网络设置：

   - `EXAMPLE_ESP_WIFI_SSID`：设置为您的 WiFi 网络的 SSID（名称）。
   - `EXAMPLE_ESP_WIFI_PASS`：设置为您的 WiFi 网络的密码。
   - `EXAMPLE_ESP_WIFI_CHANNEL`：设置 WiFi 信道（通常为 1）。
   - `EXAMPLE_MAX_STA_CONN`：设置最大站点连接数（默认为 4）。
   - `EXAMPLE_ESP_MAXIMUM_RETRY`：设置最大连接重试次数。

   - Modify the following variables in the code to match your WiFi network settings:

     - `EXAMPLE_ESP_WIFI_SSID`: Set this to your WiFi network's SSID (name).
     - `EXAMPLE_ESP_WIFI_PASS`: Set this to your WiFi network's password.
     - `EXAMPLE_ESP_WIFI_CHANNEL`: Set the WiFi channel (usually 1).
     - `EXAMPLE_MAX_STA_CONN`: Set the maximum number of station connections (default is 4).
     - `EXAMPLE_ESP_MAXIMUM_RETRY`: Set the maximum number of connection retries.

3. 使用 ESP-IDF 工具构建并烧写代码到您的 ESP32C3 设备。确保选择了正确的目标和串口端口。

   - Build and flash the code to your ESP32C3 device using the ESP-IDF tools. Make sure you have selected the correct target and serial port.

4. 烧写完成后，ESP32C3 将启动为一个软接入点（AP），使用您在步骤 2 中配置的 SSID 和密码。

   - After flashing, the ESP32C3 will start as a soft access point (AP) with the SSID and password you configured in step 2.

## 使用方法 - Usage

1. 使用您配置的 SSID 和密码，将计算机或移动设备连接到 ESP32C3 创建的 WiFi 网络。

   - Connect your computer or mobile device to the WiFi network created by the ESP32C3 using the SSID and password you configured.

2. 打开 Web 浏览器并导航到 ESP32C3 的 IP 地址。您可以在 ESP32C3 启动时的串口控制台输出中找到 IP 地址。

   - Open a web browser and navigate to the ESP32C3's IP address. You can find the IP address in the serial console output of the ESP32C3 when it starts.

3. 您将看到一个 Web 页面，在该页面上，您可以输入要为 ESP32C3 配置的 WiFi SSID 和密码。

   - You will be presented with a web page where you can enter the WiFi SSID and password you want to configure for the ESP32C3.

4. 输入 WiFi SSID 和密码，然后单击 "提交" 按钮。

   - Enter the WiFi SSID and password, then click the "Submit" button.

5. ESP32C3 将处理输入的数据并尝试连接到指定的 WiFi 网络。

   - The ESP32C3 will process the entered data and attempt to connect to the specified WiFi network.

6. 您可以在串口控制台中监视 ESP32C3 的状态。它将指示连接是否成功。

   - You can monitor the ESP32C3's status in the serial console. It will indicate whether the connection was successful or not.

## 故障排除 - Troubleshooting

如果遇到任何问题，请考虑以下故障排除步骤：

If you encounter any issues, consider the following troubleshooting steps:

- 检查串口控制台是否有任何错误消息或调试信息。

   - Check the serial console for any error messages or debug information.

- 确保您输入了正确的 WiFi SSID 和密码。

   - Ensure that you entered the correct WiFi SSID and password.

- 验证您的 ESP32C3 设备是否在 WiFi 网络的范围内。

   - Verify that your ESP32C3 device is within range of your WiFi network.

- 确保您正在连接到具有稳定互联网连接的网络。

   - Make sure you have a stable internet connection on the network you're trying to connect to.

## 自定义 - Customization

您可以进一步自定义此代码以满足您的特定需求。例如，您可以修改 Web 页面的外观，添加附加的配置选项，或将其与 ESP32C3 项目的其他组件集成。

   - You can further customize this code to fit your specific requirements. For example, you can modify the web page's appearance, add additional configuration options, or integrate it with other components of your ESP32C3 project.

## 结论 - Conclusion

您已成功设置了一个用于配置 WiFi 参数的 ESP32C3 Web 服务器。这可以是物联网设备的有用功能，用于连接到不同的 WiFi 网络或用于 ESP32C3 基础项目的初始设置。

   - You have successfully set up an ESP32C3 web server for configuring WiFi parameters. This can be a useful feature for IoT devices that need to connect to different WiFi networks or for