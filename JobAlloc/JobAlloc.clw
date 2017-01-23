; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CJobAllocDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "JobAlloc.h"

ClassCount=3
Class1=CJobAllocApp
Class2=CJobAllocDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_JOBALLOC_DIALOG

[CLS:CJobAllocApp]
Type=0
HeaderFile=JobAlloc.h
ImplementationFile=JobAlloc.cpp
Filter=N

[CLS:CJobAllocDlg]
Type=0
HeaderFile=JobAllocDlg.h
ImplementationFile=JobAllocDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CJobAllocDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=JobAllocDlg.h
ImplementationFile=JobAllocDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_JOBALLOC_DIALOG]
Type=1
Class=CJobAllocDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_JOB_INFO,static,1342308352

