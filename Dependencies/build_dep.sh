
if grep -Eqi "CentOS" /etc/issue || grep -Eq "CentOS" /etc/*-release; then
    DISTRO='CentOS'
    PM='yum'
    PM_CMD='install'
elif grep -Eqi "Red Hat Enterprise Linux Server" /etc/issue || grep -Eq "Red Hat Enterprise Linux Server" /etc/*-release; then
    DISTRO='RHEL'
    PM='yum' 
    PM_CMD='install'
elif grep -Eqi "Aliyun" /etc/issue || grep -Eq "Aliyun" /etc/*-release; then
    DISTRO='Aliyun'
    PM='yum'
    PM_CMD='install'
elif grep -Eqi "Fedora" /etc/issue || grep -Eq "Fedora" /etc/*-release; then
    DISTRO='Fedora'
    PM='yum'
    PM_CMD='install'
elif grep -Eqi "Debian" /etc/issue || grep -Eq "Debian" /etc/*-release; then
    DISTRO='Debian'
    PM='apt-get'
    PM_CMD='install'
elif grep -Eqi "Ubuntu" /etc/issue || grep -Eq "Ubuntu" /etc/*-release; then
    DISTRO='Ubuntu'
    PM='apt-get'
    PM_CMD='install'
elif grep -Eqi "Raspbian" /etc/issue || grep -Eq "Raspbian" /etc/*-release; then
    DISTRO='Raspbian'
    PM='apt-get'
    PM_CMD='install'
elif grep -Eqi "Manjaro" /etc/issue || grep -Eq "Manjaro" /etc/*-release; then 
    DISTRO='Manjaro'
    PM='pacman'    
    PM_CMD='-S'
else
    DISTRO='unknow'
fi


sysOS=`uname -s`

if [ $sysOS == "Darwin" ];then
    brew install gcc@7
elif [ $sysOS == "Linux" ];then
    if [ $PM == "apt-get" ]; then
        sudo apt-get -y install g++-7
        sudo apt-get -y install libtool
        sudo apt-get -y install libstdc++-static
        sudo apt-get -y install libreadline6-dev
        sudo apt-get -y install libncurses5-dev
        sudo apt-get -y install pkg-config
    elif [$PM == "yum" ]; then
        sudo yum -y install centos-release-scl
        sudo yum -y install devtoolset-7
        sudo scl enable devtoolset-7 bash
        sudo yum -y install libtool
        sudo yum -y install readline-devel
        sudo yum -y install ncurses-devel
        sudo yum -y install libstdc++-static
        sudo yum -y install pkg-config
    elif [$PM == "pacman"]; then
	sudo pacman -S --noconfirm base-devel    
	sudo pacman -S --noconfirm g++
    fi

fi

mkdir lib
mkdir ./lib/Release/
mkdir ./lib/Debug/

git submodule update --init --recursive

chmod 777 *.sh

./build_hiredis.sh
./build_vcpkg.sh
./build_lua.sh

if [ $sysOS == "Darwin" ];then
    cp -r -f ./vcpkg/installed/x64-osx/lib/* ./lib/Release/
    cp -r -f ./vcpkg/installed/x64-osx/debug/lib/* ./lib/Debug/

    cp -r -f ./vcpkg/installed/x64-osx/tools/protobuf/* ../NFComm/NFMessageDefine/

elif [ $sysOS == "Linux" ];then
    cp -r -f ./vcpkg/installed/x64-linux/lib/* ./lib/Release/
    cp -r -f ./vcpkg/installed/x64-linux/debug/lib/* ./lib/Debug/

    cp -r -f ./vcpkg/installed/x64-linux/tools/protobuf/* ../NFComm/NFMessageDefine/
fi
