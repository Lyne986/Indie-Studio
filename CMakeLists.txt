cmake_minimum_required(VERSION 3.11)

# set the project name
project(bomberman)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
if (Win32)
    set(Boost_INCLUDE_DIR "C:/Program Files/boost/boost_1_79_0")
    set(BOOST_LIBRARYDIR "C:/Program Files/boost/boost_1_79_0/libs")
endif (WIN32)

find_package(Boost COMPONENTS system filesystem)

set (raylib_DIR cmake)
FIND_PACKAGE(raylib REQUIRED)

set(SRC
    src/main.cpp
    src/Lib/MyWindow.cpp
    src/Lib/MyTransform.cpp
    src/Lib/MyEvent.cpp
    src/Lib/MyCamera.cpp
    src/Lib/MyImage.cpp
    src/Lib/MyTexture.cpp
    src/Lib/MyModel.cpp
    src/Lib/MyMesh.cpp
    src/Lib/MyText.cpp
    src/Lib/MyEasing.cpp
    src/Lib/Shapes/MyRectangle.cpp
    src/Lib/Audio/MyAudio.cpp
    src/Lib/Audio/MyMusic.cpp
    src/Lib/Audio/MySound.cpp
    src/ECS/Components/AButton.cpp
    src/ECS/Components/ACursor.cpp
    src/ECS/Components/ADestroyable.cpp
    src/ECS/Components/Model3D.cpp
    src/ECS/Components/Map3D.cpp
    src/ECS/Components/Timer.cpp
    src/ECS/Components/Effect.cpp
    src/ECS/Systems/Object2D.cpp
    src/ECS/Systems/Object3D.cpp
    src/ECS/Systems/Clickable.cpp
    src/ECS/Systems/Movable3D.cpp
    src/ECS/Systems/Movable2D.cpp
    src/ECS/Systems/Collider.cpp
    src/Objects/MainCamera.cpp
    src/Objects/MapManager.cpp
    src/Objects/Animations/GameIntro.cpp
    src/Objects/Animations/GameOutro.cpp
    src/Objects/Buttons/Quit.cpp
    src/Objects/Buttons/Back.cpp
    src/Objects/Buttons/BackSetting.cpp
    src/Objects/Buttons/Fps.cpp
    src/Objects/Buttons/Title.cpp
    src/Objects/Buttons/GameButton.cpp
    src/Objects/Buttons/Setting.cpp
    src/Objects/Buttons/Local.cpp
    src/Objects/Buttons/Online.cpp
    src/Objects/Buttons/Add.cpp
    src/Objects/Buttons/Delete.cpp
    src/Objects/Buttons/Battle.cpp
    src/Objects/Buttons/Change.cpp
    src/Objects/Buttons/NewGame.cpp
    src/Objects/Buttons/LoadGame.cpp
    src/Objects/Cursor/SoundSetting.cpp
    src/Objects/Cursor/fpsSetting.cpp
    src/Objects/Interactables/Player.cpp
    src/Objects/Interactables/DestroyableWall.cpp
    src/Objects/Interactables/APlayer.cpp
    src/Objects/Interactables/AI/AI.cpp
    src/Objects/Interactables/AI/AIUtils.cpp
    src/Objects/Interactables/AI/easyAI.cpp
    src/Objects/Interactables/AI/intermediateAI.cpp
    src/Objects/Interactables/AI/mediumAI.cpp
    src/Objects/Interactables/AI/FindNearetPlayerCollider.cpp
    src/Objects/Interactables/AI/IsAISafe.cpp
    src/Objects/Interactables/AI/AI_PathFinding.cpp
    src/Objects/Interactables/AI/IsColliderSafe.cpp
    src/Objects/Interactables/Player.cpp
    src/Objects/Interactables/DestroyableWall.cpp
    src/Objects/Interactables/PowerUp.cpp
    src/Objects/Interactables/Bomb.cpp
    src/Objects/UI/PlayerInfo.cpp
    src/Utils/FileManager.cpp
    src/Scenes/AScene.cpp
    src/Scenes/SplashScene.cpp
    src/Scenes/GameScene.cpp
    src/Scenes/MenuScene.cpp
    src/Scenes/LobbyScene.cpp
    src/Scenes/LevelScene.cpp
    src/Scenes/SettingScene.cpp
    src/Scenes/PauseScene.cpp
    src/SceneManager.cpp
    src/Menu/Character.cpp
    src/Client/Client.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
if (WIN32)
    target_include_directories(${PROJECT_NAME} PUBLIC "C:/Program Files/boost/boost_1_79_0")
endif (WIN32)
target_include_directories(${PROJECT_NAME} PUBLIC ./src)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC raylib
    ${Boost_FILESYSTEM_LIBRARY}
)


# Do : cd build ; cmake ../; make ; ./indie
