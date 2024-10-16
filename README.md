technologies used in this project :
- Node-Red : the web server
- Arduino UNO : collect sensor values and send them to the webserver and actuate the relays based on the server command 
- nodeMcu : wifi connectivity to the webserver
- MQTT : the communication protocol
- MySQL : database used for saving and retrieving data


This project aims to create a small power distribution unit and control it via a Web based control center. The PDU has a basic functionality of:
  - Distributing electricity from a source to multiple loads 
  - Automatic source switching from the main source to the backup source and vice versa in case of power outage 
  - Sending sensor data of (current, voltage, power source) to the web server via Wi-Fi
  - Receiving control commands for each load from the server 
  - Auto source disconnecting in case of overvoltage or overcurrent 

The web server has basic functions of:
-	A User Interface : 
  Monitoring real-time load status and power consumption.
  Manual or scheduled load control for optimized energy use.
-	Data storage: 
  Securely stores power consumption and voltage data for each load, facilitating future analysis.
- Event logging: 
  Logs all power outages, overcurrent, and overvoltage events for troubleshooting and trend analysis.
- Load prioritization: 
  Enables users to prioritize critical loads based on their preferences.
- Data visualization: 
  Provides insightful graphs and analytics to understand system performance.
- Load management: 
  Allows users to set load limits according to their preferences, promoting efficient energy consumption.

  ![image](https://github.com/user-attachments/assets/9a39f579-243b-4891-95e2-47705b4571f9)

  ![image](https://github.com/user-attachments/assets/30549dba-8d34-4171-aad1-6caa90f2dabb)
  
  ![image](https://github.com/user-attachments/assets/8c13768d-98d1-43ac-9cd6-c89617adae02)

  ![image](https://github.com/user-attachments/assets/5c460f93-b0e1-4de5-a0a5-08bb770488be)

  ![image](https://github.com/user-attachments/assets/820162a2-574b-46ee-891b-d59014b487fe)

  
  ![image](https://github.com/user-attachments/assets/ba273f1e-59c4-4a86-9057-91ae6c487235)
![image](https://github.com/user-attachments/assets/9b67f0c4-ed1e-49b4-9c7e-25f3b0c48d00)

![image](https://github.com/user-attachments/assets/46441064-b68b-4d7f-a305-7e414e240219)

![image](https://github.com/user-attachments/assets/9872ce2b-6601-4ee5-b5dd-ae033e3ca10d)

![image](https://github.com/user-attachments/assets/53de7a38-9488-4848-b6cb-d476eab7cc3e)

![image](https://github.com/user-attachments/assets/9b5ef220-d508-4398-a047-673d115b6f5b)
![image](https://github.com/user-attachments/assets/aeee8dcc-e5f8-43ba-82ba-ed2cb30b52c4)
![image](https://github.com/user-attachments/assets/7764114c-b151-4f3f-bb21-163d3dfd28a9)
![image](https://github.com/user-attachments/assets/f873f29b-d765-448b-9617-c1a496f94248)






https://github.com/user-attachments/assets/51db2189-32e1-4de6-b7f9-0cbece57d60b














  
