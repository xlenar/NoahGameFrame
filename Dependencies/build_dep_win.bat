
@rem git submodule update --init --recursive

@rem git clone https://github.com/Microsoft/vcpkg.git

@rem cd Dependencies

@rem rm -rf vcpkg
@rem rm -rf vcpkg_for_nf

@rem rd /s /q vcpkg
@rem rd /s /q vcpkg_for_nf

@rem git clone https://github.com/ketoo/vcpkg_for_nf.git

@rem rename vcpkg_for_nf vcpkg
cd vcpkg

7z.exe x installed\x64-windows-static\debug\lib\libprotobufd.zip  -oinstalled\x64-windows-static\debug\lib\
7z.exe x installed\x64-windows-static\lib\libprotobuf.rar -oinstalled\x64-windows-static\lib\

cd ..

xcopy vcpkg\installed\x64-windows-static\lib lib\Release\ /s /e /Y
xcopy vcpkg\installed\x64-windows-static\bin ..\_Out\Release\  /s /e /Y

xcopy vcpkg\installed\x64-windows-static\debug\lib lib\Debug\  /s /e /Y
xcopy vcpkg\installed\x64-windows-static\debug\bin ..\_Out\Debug\  /s /e /Y

xcopy vcpkg\installed\x64-windows-static\tools\protobuf\protoc.exe ..\NFComm\NFMessageDefine\ /s /e /Y

@rem cd..
