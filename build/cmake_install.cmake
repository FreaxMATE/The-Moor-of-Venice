# Install script for directory: /home/kunruh/src/The-Moor-of-Venice

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/var/empty/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/nix/store/888bkaqdpfpx72dd8bdc69qsqlgbhcvf-gcc-wrapper-13.3.0/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/MyGame" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/MyGame")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/MyGame"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/kunruh/src/The-Moor-of-Venice/build/bin/MyGame")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/MyGame" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/MyGame")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/nix/store/888bkaqdpfpx72dd8bdc69qsqlgbhcvf-gcc-wrapper-13.3.0/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/MyGame")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/kunruh/src/The-Moor-of-Venice/build/CMakeFiles/MyGame.dir/install-cxx-module-bmi-noconfig.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/kunruh/src/The-Moor-of-Venice/include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES
    "/nix/store/ql0wgd6slp48h3z4119nfnvds7nyz8fm-sfml-2.5.1/lib/libsfml-system.so.2.5.1"
    "/nix/store/ql0wgd6slp48h3z4119nfnvds7nyz8fm-sfml-2.5.1/lib/libsfml-window.so.2.5.1"
    "/nix/store/ql0wgd6slp48h3z4119nfnvds7nyz8fm-sfml-2.5.1/lib/libsfml-graphics.so.2.5.1"
    "/nix/store/ql0wgd6slp48h3z4119nfnvds7nyz8fm-sfml-2.5.1/lib/libsfml-audio.so.2.5.1"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/assets" TYPE DIRECTORY FILES "/home/kunruh/src/The-Moor-of-Venice/assets/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE PROGRAM FILES "/home/kunruh/src/The-Moor-of-Venice/run_my_game.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES
    "/nix/store/ql0wgd6slp48h3z4119nfnvds7nyz8fm-sfml-2.5.1/lib/libsfml-graphics.so.2.5"
    "/nix/store/ql0wgd6slp48h3z4119nfnvds7nyz8fm-sfml-2.5.1/lib/libsfml-audio.so.2.5"
    "/nix/store/ql0wgd6slp48h3z4119nfnvds7nyz8fm-sfml-2.5.1/lib/libsfml-window.so.2.5"
    "/nix/store/ql0wgd6slp48h3z4119nfnvds7nyz8fm-sfml-2.5.1/lib/libsfml-system.so.2.5"
    "/nix/store/4gk773fqcsv4fh2rfkhs9bgfih86fdq8-gcc-13.3.0-lib/lib/libstdc++.so.6"
    "/nix/store/nqb2ns2d1lahnd5ncwmn6k84qfd7vx2k-glibc-2.40-36/lib/libm.so.6"
    "/nix/store/4gk773fqcsv4fh2rfkhs9bgfih86fdq8-gcc-13.3.0-lib/lib/libgcc_s.so.1"
    "/nix/store/nqb2ns2d1lahnd5ncwmn6k84qfd7vx2k-glibc-2.40-36/lib/libc.so.6"
    "/nix/store/kynlrr98p2c235b00c72b14apn7l8l4y-libglvnd-1.7.0/lib/libGL.so.1"
    "/nix/store/y9q2vynfv3gbkgcf31hnvz2xlxswc6bj-glu-9.0.3/lib/libGLU.so.1"
    "/nix/store/zcq4irdcgn3ljqdnlpm2zjp7f1kw9jvm-libX11-1.8.10/lib/libX11.so.6"
    "/nix/store/k4wbhldwg6lfsiaxmp6fjzma8qdh3vm5-libXrandr-1.5.4/lib/libXrandr.so.2"
    "/nix/store/49i3byz2r6q1dw30byvhxr8lm5bix851-freetype-2.13.3/lib/libfreetype.so.6"
    "/nix/store/xq37p60qlc94whxqpnvn8pkjsh63181s-openal-soft-1.23.1/lib/libopenal.so.1"
    "/nix/store/n4ma81w9ln2vnpdb0k51r85rbqjg5pdw-libvorbis-1.3.7/lib/libvorbisenc.so.2"
    "/nix/store/n4ma81w9ln2vnpdb0k51r85rbqjg5pdw-libvorbis-1.3.7/lib/libvorbisfile.so.3"
    "/nix/store/n4ma81w9ln2vnpdb0k51r85rbqjg5pdw-libvorbis-1.3.7/lib/libvorbis.so.0"
    "/nix/store/3q578mzf8nfihvgp2xp3zg8gmajl4whs-libogg-1.3.5/lib/libogg.so.0"
    "/nix/store/sklhjxx3i3684xb396hmqydllg0x93lc-flac-1.4.3/lib/libFLAC.so.12"
    "/nix/store/qzpdmv5hnf52ln42hkbc874q37rrmbyy-systemd-minimal-libs-256.10/lib/libudev.so.1"
    "/nix/store/nqb2ns2d1lahnd5ncwmn6k84qfd7vx2k-glibc-2.40-36/lib/libpthread.so.0"
    "/nix/store/nqb2ns2d1lahnd5ncwmn6k84qfd7vx2k-glibc-2.40-36/lib/librt.so.1"
    "/nix/store/nqb2ns2d1lahnd5ncwmn6k84qfd7vx2k-glibc-2.40-36/lib64/ld-linux-x86-64.so.2"
    "/nix/store/kynlrr98p2c235b00c72b14apn7l8l4y-libglvnd-1.7.0/lib/libGLX.so.0"
    "/nix/store/hi1mbz7s24l63w1m9sy9ynl8yjvb2f46-libXext-1.3.6/lib/libXext.so.6"
    "/nix/store/kynlrr98p2c235b00c72b14apn7l8l4y-libglvnd-1.7.0/lib/libGLdispatch.so.0"
    "/nix/store/kynlrr98p2c235b00c72b14apn7l8l4y-libglvnd-1.7.0/lib/libOpenGL.so.0"
    "/nix/store/c25p9xs9n6grwx4i4l4kmz09scgcav4b-libxcb-1.17.0/lib/libxcb.so.1"
    "/nix/store/bnfmimcfan36gg0g488c5hksg8nyr16y-libXrender-0.9.11/lib/libXrender.so.1"
    "/nix/store/l5g2v1jgfyf3j0jp9iv5b79fi8yrwzpp-zlib-1.3.1/lib/libz.so.1"
    "/nix/store/cp24rhch20cbns9c9jsw7b6h78rlci3z-bzip2-1.0.8/lib/libbz2.so.1"
    "/nix/store/1mldak8ls62za08yckviy3zfpzim4aiz-libpng-apng-1.6.43/lib/libpng16.so.16"
    "/nix/store/m70hxn0ph0gc3gnvkpjb9631655nnw6z-brotli-1.1.0-lib/lib/libbrotlidec.so.1"
    "/nix/store/p4mjdx6l2q4ff3ssjwh989rlw4xwljb7-alsa-lib-1.2.12/lib/libasound.so.2"
    "/nix/store/jfvppvfqk1bg6pm3dsgypn389wvlq1q2-libpulseaudio-17.0/lib/libpulse.so.0"
    "/nix/store/dy7mkaigag2fs7bdvnvn66f4x8syjwks-pipewire-1.2.7/lib/libpipewire-0.3.so.0"
    "/nix/store/4gk773fqcsv4fh2rfkhs9bgfih86fdq8-gcc-13.3.0-lib/lib/libatomic.so.1"
    "/nix/store/la3w078ipfi6l985lrfrgckvx2c4lkff-dbus-1.14.10-lib/lib/libdbus-1.so.3"
    "/nix/store/nqb2ns2d1lahnd5ncwmn6k84qfd7vx2k-glibc-2.40-36/lib/libmvec.so.1"
    "/nix/store/ay424b8c8zv4jviiml73b3qdgv8r83r7-libcap-2.70-lib/lib/libcap.so.2"
    "/nix/store/6a49zj2wva8nxw7sidw9j9bp2nifscbw-libXau-1.0.11/lib/libXau.so.6"
    "/nix/store/1x0fg2bhf14lk83458c4iir92hc1njjh-libXdmcp-1.1.5/lib/libXdmcp.so.6"
    "/nix/store/m70hxn0ph0gc3gnvkpjb9631655nnw6z-brotli-1.1.0-lib/lib/libbrotlicommon.so.1"
    "/nix/store/jfvppvfqk1bg6pm3dsgypn389wvlq1q2-libpulseaudio-17.0/lib/pulseaudio/libpulsecommon-17.0.so"
    "/nix/store/7p0ma0wx3l9ffxdh1zbfn90n2dxazyiq-systemd-minimal-256.10/lib/libsystemd.so.0"
    "/nix/store/lpdbjki6ssrxg2z2k6bcl9wd87di1vwm-libsndfile-1.2.2/lib/libsndfile.so.1"
    "/nix/store/wx88wyz0rzkdpb89b9031bdiq708068q-libopus-1.5.2/lib/libopus.so.0"
    "/nix/store/c8w6papjxdk1ajvlr2qx6sqxgs17v0dr-libmpg123-1.32.9/lib/libmpg123.so.0"
    "/nix/store/sdcrlkh3p8n4yvlczl8qqnm0v168gyx4-lame-3.100-lib/lib/libmp3lame.so.0"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/glibc" TYPE FILE FILES
    "/nix/store/nqb2ns2d1lahnd5ncwmn6k84qfd7vx2k-glibc-2.40-36/lib/libc.so.6"
    "/nix/store/nqb2ns2d1lahnd5ncwmn6k84qfd7vx2k-glibc-2.40-36/lib/libpthread.so.0"
    "/nix/store/nqb2ns2d1lahnd5ncwmn6k84qfd7vx2k-glibc-2.40-36/lib/librt.so.1"
    "/nix/store/nqb2ns2d1lahnd5ncwmn6k84qfd7vx2k-glibc-2.40-36/lib/libdl.so.2"
    "/nix/store/nqb2ns2d1lahnd5ncwmn6k84qfd7vx2k-glibc-2.40-36/lib/libm.so.6"
    "/nix/store/nqb2ns2d1lahnd5ncwmn6k84qfd7vx2k-glibc-2.40-36/lib64/ld-linux-x86-64.so.2"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
  file(WRITE "/home/kunruh/src/The-Moor-of-Venice/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
