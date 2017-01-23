; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShareClientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ShareClient.h"

ClassCount=4
Class1=CShareClientApp
Class2=CShareClientDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_DIALOG_COMP_NAME
Resource2=IDR_MAINFRAME
Resource3=IDD_SHARECLIENT_DIALOG
Class4=CCompNameDlg
Resource4=IDD_ABOUTBOX

[CLS:CShareClientApp]
Type=0
HeaderFile=ShareClient.h
ImplementationFile=ShareClient.cpp
Filter=N

[CLS:CShareClientDlg]
Type=0
HeaderFile=ShareClientDlg.h
ImplementationFile=ShareClientDlg.cpp
Filter=D
LastObject=CShareClientDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ShareClientDlg.h
ImplementationFile=ShareClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SHARECLIENT_DIALOG]
Type=1
Class=CShareClientDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_TRANSACT,button,1342242816
Control3=IDC_TRANS_INFO,static,1342308352
Control4=IDC_COMP_INFO,static,1342308352

[DLG:IDD_DIALOG_COMP_NAME]
Type=1
Class=CCompNameDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_COMPUTER_NAME,edit,1350631552

[CLS:CCompNameDlg]
Type=0
HeaderFile=CompNameDlg.h
ImplementationFile=CompNameDlg.cpp
BaseClass=CDialog

