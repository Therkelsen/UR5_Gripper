
# UR5_Gripper
dRobTek Group 6 - Second semester project for B.E. in Robotics Technology
<p align="center"> <img src="Assets/UR5.png" alt="UR5" title="UR5" width="60%" height="60%"/> </p>
<br>

## Problem
<div style="text-align: justify">A gripper for the Universal Robots UR5 robot is to be developed during this semester project. An idea could be to follow the block diagram below, but not required.</div>
<br>
<p align="center"> <img src="Assets/Diagram.png" alt="Diagram" title="Diagram" width="60%" height="60%"/> </p>
<div style="text-align: justify">It is expected that you at least develop:<br>
•	A 3D model of a gripper that can be printed or otherwise constructed.<br>
•	Electronics to control the gripper.<br>
•	A URCaps plugin for the UR controller.<br>
•	Software design of a C++ Program developed on a Raspberry PI, a PC, or possibly both.<br>
•	A modern communication interface to the gripper (e.g. OPC UA). Ideas to an interface:<br>
•	The no. of grips<br>
•	Gripper force<br>
•	Gripper distance<br>
•	Etc.<br>
<br>
The gripper must fulfil the following requirements:<br>
•	Supply voltage: 24V (from external supply – you are not allowed to use the robot controller as power supply)<br>
•	The maximum gripper power use: 600mA<br>
•	It is not allowed to use the digital I/O from the UR robot. All I/O must be done through the Raspberry Pi microcontroller. Please remember that the power output from digital I/O is very limited.<br>
</div>
<br>

## Abstract
<div style="text-align: justify">
This report presents the process of constructing and programming a gripper for the UR5-series industrial robotic arm, controlled through an XML-RPC-socket utilizing a URCap plugin on the robot. The gripper design is made for the purpose of hoisting a conventional 33 cl beverage can, which has the dimensions 122 mm in height and 65 mm in diameter. The final product is to be constructed with four main segments, firstly a URCap-plugin utilizing XML-RCP protocol to communicate with a Raspberry Pi. This single-board computer is connected to a motor, mounted to a 3D-printed gripper, which will open and close according to the XML-RPC-server method called by the URCap. Determinately, Industry 4.0 communication will run from the single-board computer to an external device, amassing and preserving information about the behaviour of the gripper.
<br>
First, the report introduces the different contents of the URCap-StarterPackage and the theoretical fundamentals of URCaps, following a walkthrough of the methods applied in building a URCap. This includes both an installation and program node fitting the criteria of the project. A more concrete view on how the individual Java-methods act together, to construct the interface and computer logics required in building a connection to an external device utilizing XML-RPC-protocol, is discussed. Furthermore, the structure of the C++-programmed XML-RPC-server will be covered, and additionally, how the different server method calls are utilized in another C++ program to instigate physical kineticism of the gripper. Thereafter, the designations and functionalities of the hardware components used will be listed and the process of modeling and printing the gripper, and the thoughts behind this design will be provided.
<br>
The proposed solution is presented in detail and discussed in terms of functionality in relation to the chosen scenario, and possible amendments, as well as thoughts on choices made throughout the process of effectuating a solution, will be shared. Lastly, the entire project will culminate in a summarized conclusion on the coalescence of URCaps, MotorControl, Industry 4.0 communication, and the 3D modeling and printing of the physical gripper - the four main segments embodying the objective of this project.
</div> 
<br>

## Introduction
<div style="text-align: justify">
The fourth industrial revolution as many in our time choose to call it, is constantly evolving, and evidently more of the industries as well as everyday processes, get automated. One of the many benefits of automation is, that the mistakes that humans make in the manual process are eliminated.
<br>
With this in mind, robots today are designed and constructed for all sorts of different purposes and in particular the 6-member robot arm has become an indispensable industrial tool, for example due to its universality.
This is not only due to the freedom of movement, but - as is the case for most robot arm manufacturers - also the freedom to switch between the robot arm tools. There are already a sea of tool manufacturers who invent everything between two- and three-finger grippers, vacuum grippers and grippers that utilize the so-called "soft robotics" technology. All these types of grippers, which can be used, for example, together with the robot arms from Universal Robots, which with their URCap software largely achieve the ambition of creating a universal robot arm.
<br>
The possibility of custom configuration through URCap allows for this project, where we have been given the task of designing and developing a gripper for a UR5 robot arm. This must be able to lift one or more objects of your choice. Here we have chosen to design a gripper that aims to lift a can, more specifically a standard 33 cl soda / beer can. The gripper itself is modeled in the CAD program Fusion 360, and is then physically made of 3D-printed plastic. The movements of the gripper are controlled by a DC motor, which is connected to a Raspberry Pi on which a motor driver is programmed using C++, to control the movement of the DC motor.
<br>
Furthermore, a URCap plugin has been developed in order to create a user-friendly interface. This URCap, consisting of a so-called Program Node and an Installation Node, establishes an XML-RPC connection to a server on the Raspberry Pi, thereby controlling the activation of the gripper's various functions.
</div>
<br>

## Conclusion
<div style="text-align: justify">

</div>
