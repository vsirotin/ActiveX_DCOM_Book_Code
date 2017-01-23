; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAcDocView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AcDoc.h"
LastPage=0

ClassCount=6
Class1=CAcDocApp
Class2=CAcDocDoc
Class3=CAcDocView
Class4=CMainFrame
Class5=CInPlaceFrame

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource4=IDR_CNTR_INPLACE
Resource5=IDR_SRVR_INPLACE
Resource6=IDR_SRVR_EMBEDDED
Resource7=IDD_ACDOC_FORM
Class6=CAboutDlg

[CLS:CAcDocApp]
Type=0
HeaderFile=AcDoc.h
ImplementationFile=AcDoc.cpp
Filter=N

[CLS:CAcDocDoc]
Type=0
HeaderFile=AcDocDoc.h
ImplementationFile=AcDocDoc.cpp
Filter=N
BaseClass=COleServerDoc
VirtualFilter=vLODC
LastObject=CAcDocDoc

[CLS:CAcDocView]
Type=0
HeaderFile=AcDocView.h
ImplementationFile=AcDocView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=ID_EDIT_PASTE

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T

[CLS:CInPlaceFrame]
Type=0
HeaderFile=IpFrame.h
ImplementationFile=IpFrame.cpp
Filter=T


[CLS:CAboutDlg]
Type=0
HeaderFile=AcDoc.cpp
ImplementationFile=AcDoc.cpp
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
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_PASTE_SPECIAL
Command15=ID_OLE_INSERT_NEW
Command16=ID_OLE_EDIT_LINKS
Command17=ID_OLE_VERB_FIRST
Command18=ID_VIEW_TOOLBAR
Command19=ID_VIEW_STATUS_BAR
Command20=ID_APP_ABOUT
CommandCount=20

[MNU:IDR_CNTR_INPLACE]
Type=1
Class=CAcDocView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
CommandCount=9

[MNU:IDR_SRVR_INPLACE]
Type=1
Class=CAcDocView
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_PASTE_SPECIAL
Command6=ID_OLE_INSERT_NEW
Command7=ID_OLE_EDIT_LINKS
Command8=ID_OLE_VERB_FIRST
Command9=ID_VIEW_TOOLBAR
Command10=ID_APP_ABOUT
CommandCount=10

[TB:IDR_SRVR_INPLACE]
Type=1
Class=CAcDocView
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_APP_ABOUT
CommandCount=4

[MNU:IDR_SRVR_EMBEDDED]
Type=1
Class=CAcDocView
Command1=ID_FILE_UPDATE
Command2=ID_FILE_SAVE_COPY_AS
Command3=ID_FILE_PRINT
Command4=ID_FILE_PRINT_PREVIEW
Command5=ID_FILE_PRINT_SETUP
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_EDIT_PASTE_SPECIAL
Command12=ID_OLE_INSERT_NEW
Command13=ID_OLE_EDIT_LINKS
Command14=ID_OLE_VERB_FIRST
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_APP_ABOUT
CommandCount=17

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
Command15=ID_CANCEL_EDIT_CNTR
CommandCount=15

[ACL:IDR_CNTR_INPLACE]
Type=1
Class=CAcDocView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
Command7=ID_CANCEL_EDIT_CNTR
CommandCount=7

[ACL:IDR_SRVR_INPLACE]
Type=1
Class=CAcDocView
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_CANCEL_EDIT_SRVR
CommandCount=9

[ACL:IDR_SRVR_EMBEDDED]
Type=1
Class=CAcDocView
Command1=ID_FILE_UPDATE
Command2=ID_FILE_PRINT
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_NEXT_PANE
Command12=ID_PREV_PANE
Command13=ID_CANCEL_EDIT_CNTR
CommandCount=13

[DLG:IDD_ACDOC_FORM]
Type=1
Class=CAcDocView
ControlCount=11
Control1=IDC_LIST1,listbox,1352728835
Control2=IDC_ID,edit,1484849280
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COUNT,edit,1350639744
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PRICE,edit,1350631552
Control7=IDC_ELEM_TO_LIST,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_TYP,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_NEW_ELEM,button,1342242816

[TB:IDR_MAINFRAME]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

