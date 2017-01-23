
AxDATLCircuitps.dll: dlldata.obj AxDATLCircuit_p.obj AxDATLCircuit_i.obj
	link /dll /out:AxDATLCircuitps.dll /def:AxDATLCircuitps.def /entry:DllMain dlldata.obj AxDATLCircuit_p.obj AxDATLCircuit_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL $<

clean:
	@del AxDATLCircuitps.dll
	@del AxDATLCircuitps.lib
	@del AxDATLCircuitps.exp
	@del dlldata.obj
	@del AxDATLCircuit_p.obj
	@del AxDATLCircuit_i.obj
