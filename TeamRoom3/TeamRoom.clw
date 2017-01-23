; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTeamRoomCtrl
LastTemplate=COlePropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TeamRoom.h"
CDK=Y

ClassCount=5
Class1=CTeamRoomCtrl
Class2=CTeamRoomPropPage

ResourceCount=4
Resource1=IDD_DIALOG_ORDER
LastPage=0
Resource2=IDD_PROPPAGE_TEAMROOM1
Class3=CRoom
Class4=COrderDlg
Resource3=IDD_PROPPAGE_TEAMROOM
Class5=CTeamRoomDetails
Resource4=IDD_ABOUTBOX_TEAMROOM

[CLS:CTeamRoomCtrl]
Type=0
HeaderFile=TeamRoomCtl.h
ImplementationFile=TeamRoomCtl.cpp
Filter=W
BaseClass=COleControl
VirtualFilter=wWC
LastObject=CTeamRoomCtrl

[CLS:CTeamRoomPropPage]
Type=0
HeaderFile=TeamRoomPpg.h
ImplementationFile=TeamRoomPpg.cpp
Filter=D
LastObject=IDC_ROOM_AREA
BaseClass=COlePropertyPage
VirtualFilter=idWC

[DLG:IDD_ABOUTBOX_TEAMROOM]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PROPPAGE_TEAMROOM]
Type=1
Class=CTeamRoomPropPage
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_ROOM_COUNT,edit,1484849280
Control3=IDC_STATIC,static,1342308352
Control4=IDC_ROOM_AREA,edit,1484849280

[CLS:CRoom]
Type=0
HeaderFile=Room.h
ImplementationFile=Room.cpp
BaseClass=CCmdTarget
Filter=N
VirtualFilter=C

[DLG:IDD_DIALOG_ORDER]
Type=1
Class=COrderDlg
ControlCount=15
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COUNT,edit,1484849280
Control7=IDC_STATIC,static,1342308352
Control8=IDC_SUM,edit,1484849280
Control9=IDC_INFO_ALL,edit,1352728708
Control10=IDC_STATIC,static,1342308352
Control11=IDC_PRICE,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_INFO,edit,1352728708
Control14=IDC_STATIC,button,1342177287
Control15=IDC_STATIC,button,1342177287

[CLS:COrderDlg]
Type=0
HeaderFile=OrderDlg.h
ImplementationFile=OrderDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=COrderDlg

[DLG:IDD_PROPPAGE_TEAMROOM1]
Type=1
Class=CTeamRoomDetails
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_CHANGE_CRL,button,1342242816
Control4=IDC_TEAMS,combobox,1344339970
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_ORD_COUNT,edit,1484849280
Control9=IDC_STATIC,static,1342308352
Control10=IDC_ORD_SUM,edit,1484849280

[CLS:CTeamRoomDetails]
Type=0
HeaderFile=TeamRoomDetails.h
ImplementationFile=TeamRoomDetails.cpp
BaseClass=COlePropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CTeamRoomDetails

