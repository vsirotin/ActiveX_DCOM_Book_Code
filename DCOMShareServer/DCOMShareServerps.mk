
DCOMShareServerps.dll: dlldata.obj DCOMShareServer_p.obj DCOMShareServer_i.obj
	link /dll /out:DCOMShareServerps.dll /def:DCOMShareServerps.def /entry:DllMain dlldata.obj DCOMShareServer_p.obj DCOMShareServer_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL $<

clean:
	@del DCOMShareServerps.dll
	@del DCOMShareServerps.lib
	@del DCOMShareServerps.exp
	@del dlldata.obj
	@del DCOMShareServer_p.obj
	@del DCOMShareServer_i.obj
