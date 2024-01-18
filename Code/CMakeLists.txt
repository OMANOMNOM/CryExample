cmake_minimum_required (VERSION 3.14)
set(CRYENGINE_DIR "C:/Users/jonat/AppData/Local/Programs/CRYENGINE Launcher/Engines/crytek/cryengine-57-lts/5.7.1" CACHE STRING "CRYENGINE root directory.")
set(TOOLS_CMAKE_DIR "${CRYENGINE_DIR}/Tools/CMake")

set(PROJECT_BUILD 1)
set(PROJECT_DIR "${CMAKE_SOURCE_DIR}/../")

include("${TOOLS_CMAKE_DIR}/InitialSetup.cmake")
include("${TOOLS_CMAKE_DIR}/CommonOptions.cmake")

add_subdirectory("${CRYENGINE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/CRYENGINE")

include("${TOOLS_CMAKE_DIR}/Configure.cmake")
start_sources()

sources_platform(ALL)
add_sources("Code_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "Root"
		"GamePlugin.cpp"
		"StdAfx.cpp"
		"GamePlugin.h"
		"StdAfx.h"
)
add_sources("Depreicated_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "Depreicated"
		"Depreicated/Player.cpp"
		"Depreicated/SpawnPoint.cpp"
		"Depreicated/Player.h"
		"Depreicated/SpawnPoint.h"
)
add_sources("Editor Examples_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "Editor Examples"
)
add_sources("Console Commands_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "Editor Examples\\\\Console Commands"
		"Editor Examples/Console Commands/ConsoleCommands.cpp"
		"Editor Examples/Console Commands/ConsoleCommands.h"
)
add_sources("Console Variables (CVARs)_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "Editor Examples\\\\Console Variables (CVARs)"
		"Editor Examples/Console Variables (CVARs)/ConsoleVariable.cpp"
		"Editor Examples/Console Variables (CVARs)/ConsoleVariable.h"
)
add_sources("EntityComponent basics_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "EntityComponent basics"
)
add_sources("Component Properties_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "EntityComponent basics\\\\Component Properties"
)
add_sources("GroupedComponentProperties_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "EntityComponent basics\\\\Component Properties\\\\GroupedComponentProperties"
		"EntityComponent basics/Component Properties/GroupedComponentProperties/GroupedComponentProperties.cpp"
		"EntityComponent basics/Component Properties/GroupedComponentProperties/GroupedComponentProperties.h"
)
add_sources("MoreComponentProperties_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "EntityComponent basics\\\\Component Properties\\\\MoreComponentProperties"
		"EntityComponent basics/Component Properties/MoreComponentProperties/SimpleComponentProperty.cpp"
		"EntityComponent basics/Component Properties/MoreComponentProperties/SimpleComponentProperty.h"
)
add_sources("Simple Component Properties Example_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "EntityComponent basics\\\\Component Properties\\\\Simple Component Properties Example"
		"EntityComponent basics/Component Properties/Simple Component Properties Example/SimpleComponentProperty.cpp"
		"EntityComponent basics/Component Properties/Simple Component Properties Example/SimpleComponentProperty.h"
)
add_sources("Events_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "EntityComponent basics\\\\Events"
		"EntityComponent basics/Events/EntityEvents.cpp"
		"EntityComponent basics/Events/EntityEvents.h"
)
add_sources("Input Examples_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "EntityComponent basics\\\\Input Examples"
		"EntityComponent basics/Input Examples/InputEntity.cpp"
		"EntityComponent basics/Input Examples/InputEntity.h"
)
add_sources("Timers_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "EntityComponent basics\\\\Timers"
		"EntityComponent basics/Timers/TimerComponent.cpp"
		"EntityComponent basics/Timers/TimerComponent.h"
)
add_sources("EntityComponent Minimal_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "EntityComponent Minimal"
		"EntityComponent Minimal/BlankComponent.cpp"
		"EntityComponent Minimal/BlankComponent.h"
)
add_sources("Physics Examples_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "Physics Examples"
)
add_sources("Collision Examples_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "Physics Examples\\\\Collision Examples"
		"Physics Examples/Collision Examples/CollisionComponent.cpp"
		"Physics Examples/Collision Examples/CollisionComponent.h"
)
add_sources("Raycasting Examples_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "Physics Examples\\\\Raycasting Examples"
		"Physics Examples/Raycasting Examples/Raycasting.cpp"
		"Physics Examples/Raycasting Examples/Raycasting.h"
)
add_sources("Schematyc Examples_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "Schematyc Examples"
)
add_sources("Schematyc Function examples_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "Schematyc Examples\\\\Schematyc Function examples"
		"Schematyc Examples/Schematyc Function examples/SchematycFunction.cpp"
		"Schematyc Examples/Schematyc Function examples/SchematycFunction.h"
)
add_sources("Schematyc Properties examples_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "Schematyc Examples\\\\Schematyc Properties examples"
		"Schematyc Examples/Schematyc Properties examples/SchematycProperties.cpp"
		"Schematyc Examples/Schematyc Properties examples/SchematycProperties.h"
)
add_sources("Schematyc Signals examples_uber.cpp"
    PROJECTS Game
    SOURCE_GROUP "Schematyc Examples\\\\Schematyc Signals examples"
		"Schematyc Examples/Schematyc Signals examples/SchematycSignal.cpp"
		"Schematyc Examples/Schematyc Signals examples/SchematycSignal.h"
)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/CVarOverrides.h")
    add_sources("NoUberFile"
        PROJECTS Game
        SOURCE_GROUP "Root"
            "CVarOverrides.h"
    )
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/EngineDefineOverrides.h")
    add_sources("NoUberFile"
        PROJECTS Game
        SOURCE_GROUP "Root"
            "EngineDefineOverrides.h"
    )
endif()
end_sources()

CryGameModule(Game FORCE_SHARED PCH "StdAfx.cpp" SOLUTION_FOLDER "Project")

target_include_directories(${THIS_PROJECT}
PRIVATE
    "${CRYENGINE_DIR}/Code/CryEngine/CryCommon"
    "${CRYENGINE_DIR}/Code/CryEngine/CryAction"
    "${CRYENGINE_DIR}/Code/CryEngine/CrySchematyc/Core/Interface"
    "${CRYENGINE_DIR}/Code/CryPlugins/CryDefaultEntities/Module"
)

if(CMAKE_CXX_COMPILER_ID MATCHES "[Cc]lang")
    target_compile_options(${THIS_PROJECT} PRIVATE
        -Wno-unused-variable
        -Wno-reorder
        -Wno-unknown-pragmas
        -Wno-parentheses
        -Wno-switch
        -Wno-format
        -Wno-dynamic-class-memaccess
        -Wno-unused-private-field
        -Wno-unused-value
        -Wno-invalid-offsetof
        -Wno-multichar
        -Wno-char-subscripts
        -Wno-null-conversion
        -Wno-empty-body
        -Wno-unused-lambda-capture
        -Wno-unused-function
        -Wno-tautological-constant-out-of-range-compare
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${THIS_PROJECT} PRIVATE
        -Wno-unused-function
        -Wno-unused-value
        -Wno-unused-variable
        -Wno-aligned-new
        -Wno-int-in-bool-context
        -Wno-invalid-offsetof
        -Wno-comment
        -Wno-sign-compare
        -Wno-unused-but-set-variable
        -Wno-maybe-uninitialized
        -Wno-misleading-indentation
        -Wno-unused-result
        -Wno-unknown-pragmas
        -Wno-multichar
        -Wno-strict-aliasing
        -Wno-char-subscripts
        -Wno-conversion-null
        -Wno-reorder
        -Wno-parentheses
        -Wno-format
        -Wno-switch
    )
endif()


if(OPTION_ENGINE)
    if(NOT EXISTS "${CRYENGINE_DIR}/Code/Sandbox/EditorQt")
        add_library(Editor STATIC "${CRYENGINE_DIR}/Code/CryEngine/CryCommon/CryCore/Platform/platform.h")
        set_target_properties(Editor PROPERTIES LINKER_LANGUAGE CXX)
        if (WIN32)
            set_visual_studio_debugger_command(Editor "${CRYENGINE_DIR}/bin/win_x64/Sandbox.exe" "-project \"${PROJECT_DIR}/Game.cryproject\"")
        endif()
    endif()
else()
    add_library(GameLauncher STATIC "${CRYENGINE_DIR}/Code/CryEngine/CryCommon/CryCore/Platform/platform.h")
    set_target_properties(GameLauncher PROPERTIES LINKER_LANGUAGE CXX)
    if (WIN32)
        set_visual_studio_debugger_command(GameLauncher "${CRYENGINE_DIR}/bin/win_x64/GameLauncher.exe" "-project \"${PROJECT_DIR}/Game.cryproject\"")
    endif()

    add_library(Editor STATIC "${CRYENGINE_DIR}/Code/CryEngine/CryCommon/CryCore/Platform/platform.h")
    set_target_properties(Editor PROPERTIES LINKER_LANGUAGE CXX)
    if (WIN32)
        set_visual_studio_debugger_command(Editor "${CRYENGINE_DIR}/bin/win_x64/Sandbox.exe" "-project \"${PROJECT_DIR}/Game.cryproject\"")
    endif()

    add_library(GameServer STATIC "${CRYENGINE_DIR}/Code/CryEngine/CryCommon/CryCore/Platform/platform.h")
    set_target_properties(GameServer PROPERTIES LINKER_LANGUAGE CXX)
    if (WIN32)
        set_visual_studio_debugger_command(GameServer "${CRYENGINE_DIR}/bin/win_x64/Game_Server.exe" "-project \"${PROJECT_DIR}/Game.cryproject\"")
    endif()
endif()

# Set StartUp project in Visual Studio
set_solution_startup_target(GameLauncher)

if (WIN32)
    set_visual_studio_debugger_command( ${THIS_PROJECT} "${CRYENGINE_DIR}/bin/win_x64/GameLauncher.exe" "-project \"${PROJECT_DIR}/Game.cryproject\"" )
endif()

#BEGIN-CUSTOM
# Make any custom changes here, modifications outside of the block will be discarded on regeneration.
#END-CUSTOM