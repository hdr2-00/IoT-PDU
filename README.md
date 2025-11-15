# Smart Power Distribution Unit (PDU)

An IoT-based power distribution system with automatic source switching and web monitoring. Built with Arduino, NodeMCU, and Node-RED.

## What This Does

This is a smart PDU that distributes power to multiple loads while monitoring everything through a web interface. It automatically switches between main and backup power when there's an outage, and lets you control each load remotely.

## Key Features

- **Automatic source switching** - Switches to backup power when main power fails
- **Real-time monitoring** - See voltage, current, and power consumption for each load
- **Remote control** - Turn loads on/off from the web dashboard
- **Smart protection** - Automatically disconnects on overvoltage/overcurrent
- **Load scheduling** - Set timers for automatic load control
- **Data logging** - Keeps track of power events and consumption history

## Tech Stack

- **Arduino UNO** - Reads sensors and controls relays
- **NodeMCU** - Handles WiFi communication
- **Node-RED** - Web server and dashboard
- **MQTT** - Communication between hardware and server
- **MySQL** - Stores all the data

## System Architecture

The Arduino reads sensor values and controls the relays, NodeMCU sends data to the server via MQTT, Node-RED handles the web interface and stores everything in MySQL Database .

![Load Control Interface](https://github.com/user-attachments/assets/30549dba-8d34-4171-aad1-6caa90f2dabb)


## How It Works

1. **Power Distribution** - Takes power from main or backup source and distributes to multiple loads
2. **Monitoring** - Arduino reads voltage and current sensors, sends data through NodeMCU via WiFi
3. **Auto Switching** - When main power fails, automatically switches to backup and back when restored
4. **Protection** - Continuously checks for overvoltage/overcurrent and disconnects if thresholds exceeded
5. **Control** - Send commands from web dashboard to turn loads on/off
6. **Logging** - Everything gets saved to MySQL for history and analysis

## What You Can Do With It

- Monitor power consumption of different devices
- Schedule non-critical loads to save energy
- Set up priority loads that stay on during backup power
- Get alerts when power goes out or comes back
- Analyze usage patterns to optimize energy consumption
- Remotely control devices from anywhere

## Getting Started

### You'll Need
- Arduino UNO
- NodeMCU (ESP8266)
- Voltage and current sensors
- Relay modules
- Node-RED installed
- MySQL database
- MQTT broker (like Mosquitto)

### Setup
1. Upload Arduino code to UNO
2. Upload NodeMCU code for WiFi connectivity
3. Set up MySQL database
4. Configure MQTT broker
5. Import Node-RED flows
6. Access dashboard through browser

## Future Improvements

- Mobile app for easier control
- Push notifications for critical events
- Energy cost calculations
- Integration with renewable energy sources
- Advanced scheduling with multiple time slots

## Screenshots

![Main Dashboard](https://github.com/user-attachments/assets/9a39f579-243b-4891-95e2-47705b4571f9)



![System Architecture](https://github.com/user-attachments/assets/8c13768d-98d1-43ac-9cd6-c89617adae02)

![Live Monitoring](https://github.com/user-attachments/assets/820162a2-574b-46ee-891b-d59014b487fe)

![Load Controls](https://github.com/user-attachments/assets/ba273f1e-59c4-4a86-9057-91ae6c487235)

![Load Status](https://github.com/user-attachments/assets/9b67f0c4-ed1e-49b4-9c7e-25f3b0c48d00)

![Consumption Graph](https://github.com/user-attachments/assets/46441064-b68b-4d7f-a305-7e414e240219)

![Analytics](https://github.com/user-attachments/assets/9872ce2b-6601-4ee5-b5dd-ae033e3ca10d)

![Event Log](https://github.com/user-attachments/assets/53de7a38-9488-4848-b6cb-d476eab7cc3e)

![Settings](https://github.com/user-attachments/assets/9b5ef220-d508-4398-a047-673d115b6f5b)

![Load Limits](https://github.com/user-attachments/assets/aeee8dcc-e5f8-43ba-82ba-ed2cb30b52c4)

![Scheduling](https://github.com/user-attachments/assets/7764114c-b151-4f3f-bb21-163d3dfd28a9)

![Priority Settings](https://github.com/user-attachments/assets/f873f29b-d765-448b-9617-c1a496f94248)

## Demo Video

https://github.com/user-attachments/assets/51db2189-32e1-4de6-b7f9-0cbece57d60b

---

Built as a personal project to learn IoT, web development, and power electronics. Feel free to use or modify for your own projects!
