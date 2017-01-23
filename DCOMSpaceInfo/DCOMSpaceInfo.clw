; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDCOMSpaceInfoView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DCOMSpaceInfo.h"
ODLFile=DCOMSpaceInfo.odl
LastPage=0

ClassCount=8
Class1=CDCOMSpaceInfoApp
Class2=CDCOMSpaceInfoDoc
Class3=CDCOMSpaceInfoView
Class4=CMainFrame
Class7=CConnector

ResourceCount=4
Resource1=IDD_DIALOG_COMP_NAME
Resource2=IDD_ABOUTBOX
Resource3=IDR_DCOMSPTYPE
Class5=CAboutDlg
Class6=CChildFrame
Class8=CCompNameDlg
Resource4=IDR_MAINFRAME

[CLS:CDCOMSpaceInfoApp]
Type=0
HeaderFile=DCOMSpaceInfo.h
ImplementationFile=DCOMSpaceInfo.cpp
Filter=N

[CLS:CDCOMSpaceInfoDoc]
Type=0
HeaderFile=DCOMSpaceInfoDoc.h
ImplementationFile=DCOMSpaceInfoDoc.cpp
Filter=N

[CLS:CDCOMSpaceInfoView]
Type=0
HeaderFile=DCOMSpaceInfoView.h
ImplementationFile=DCOMSpaceInfoView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CDCOMSpaceInfoView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M

[CLS:CAboutDlg]
Type=0
HeaderFile=DCOMSpaceInfo.cpp
ImplementationFile=DCOMSpaceInfo.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_DCOMSPTYPE]
Type=1
Class=CDCOMSpaceInfoView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_APP_ABOUT
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[CLS:CConnector]
Type=0
HeaderFile=Connector.h
ImplementationFile=Connector.cpp
BaseClass=CCmdTarget
Filter=N
LastObject=CConnector
VirtualFilter=C

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
Filter=D
VirtualFilter=dWC
LastObject=CCompNameDlg

