; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTaskStartDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TaskStart.h"

ClassCount=3
Class1=CTaskStartApp
Class2=CTaskStartDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TASKSTART_DIALOG

[CLS:CTaskStartApp]
Type=0
HeaderFile=TaskStart.h
ImplementationFile=TaskStart.cpp
Filter=N

[CLS:CTaskStartDlg]
Type=0
HeaderFile=TaskStartDlg.h
ImplementationFile=TaskStartDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_NEW_TASK

[CLS:CAboutDlg]
Type=0
HeaderFile=TaskStartDlg.h
ImplementationFile=TaskStartDlg.cpp
Filter=D
LastObject=IDOK

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TASKSTART_DIALOG]
Type=1
Class=CTaskStartDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_NEW_TASK,button,1342242816

