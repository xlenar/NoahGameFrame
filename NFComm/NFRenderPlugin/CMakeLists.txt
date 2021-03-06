set(ProjectName "NFRenderPlugin")

include_directories(
	./)

include_directories(
	./gl3w)

include_directories(
		./imgui)

file(GLOB NFUIPlugin_ROOT_Cpp
	*.cpp)
	
file(GLOB NFUIPlugin_ROOT_Hpp 
	*.h)

file(GLOB NFUIVIEW_ROOT_Cpp
	./UI/*.cpp)
	
file(GLOB NFUIVIEW_ROOT_Hpp 
	./UI/*.h)

file(GLOB GL_ROOT_Cpp
	./gl3w/GL/*.c)
	
file(GLOB GL_ROOT_Hpp 
	./gl3w/GL/*.h)

file(GLOB IMNODES_ROOT_Cpp
		./imnodes/*.cpp)

file(GLOB IMNODES_ROOT_Hpp
		./imnodes/*.h)


file(GLOB IMGUI_ROOT_Cpp
	./imgui/*.cpp)
	
file(GLOB IMGUI_ROOT_Hpp 
	./imgui/*.h)

file(GLOB GLAD_ROOT_Cpp
	./glad/*.cpp)
	
file(GLOB GLAD_ROOT_Hpp 
	./glad/*.h)

add_library(NFRenderPlugin STATIC
	${NFUIPlugin_ROOT_Cpp}
	${NFUIPlugin_ROOT_Hpp}
	${NFUIVIEW_ROOT_Cpp}
	${NFUIVIEW_ROOT_Hpp}
	${GL_ROOT_Cpp}
	${GL_ROOT_Hpp}
	${IMGUI_ROOT_Cpp}
	${IMGUI_ROOT_Hpp}
	${IMNODES_ROOT_Cpp}
	${IMNODES_ROOT_Hpp})
	
set_target_properties( NFRenderPlugin PROPERTIES OUTPUT_NAME_DEBUG "NFRenderPlugin")
set_target_properties( NFRenderPlugin PROPERTIES PREFIX "")
set_target_properties( NFRenderPlugin PROPERTIES
	FOLDER "NFComm/NFRenderPlugin"
	ARCHIVE_OUTPUT_DIRECTORY ${NFOutPutDir}
	RUNTIME_OUTPUT_DIRECTORY ${NFOutPutDir}
	LIBRARY_OUTPUT_DIRECTORY ${NFOutPutDir} )
	
#link_NFSDK("NFRenderPlugin")

if(UNIX)
	if (CMAKE_BUILD_TYPE MATCHES "Release")
		target_link_libraries(NFRenderPlugin libSDL2.a)
	else()
		target_link_libraries(NFRenderPlugin libSDL2d.a)
	endif()

if (APPLE)
	find_library(carbon_lib Carbon)
	find_library(iokit_lib IOKit)
	find_library(forcefeedback_lib ForceFeedback)
	find_library(cocoa_lib Cocoa)
	find_library(audiounit_lib AudioUnit)
	find_library(corevideo_lib CoreVideo)
	find_library(coreaudio_lib CoreAudio)
	find_library(opengl_lib OpenGL)
	find_library(audioToolbox_lib AudioToolbox)
	find_library(iconv_lib Iconv)
	find_library(corefoundation_lib CoreFoundation)

	set(frameworks
    ${carbon_lib}
    ${iokit_lib}
    ${forcefeedback_lib}
    ${cocoa_lib}
    ${audiounit_lib}
    ${coreaudio_lib}
    ${corevideo_lib}
    ${opengl_lib}
    ${audioToolbox_lib}
    ${iconv_lib}
    ${corefoundation_lib})


	target_link_libraries(NFRenderPlugin ${frameworks})

endif()

	target_link_libraries(NFRenderPlugin -static-libstdc++)

	add_definitions(
		-DELPP_NO_DEFAULT_LOG_FILE
	)
	
else()

endif()
