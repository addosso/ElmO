cmake_minimum_required(VERSION 3.13)
project(DiagnosticApp)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.68.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(DiagnosticApp main.cpp Diagnostic/Model/base/Ecu.h Diagnostic/VCI/base/BaseVehicleCommunicationInterface.cpp Diagnostic/VCI/base/BaseVehicleCommunicationInterface.h Diagnostic/VCI/base/WLAN/Status.h Diagnostic/VCI/base/WLAN/WLanVCI.h Diagnostic/VCI/base/WLAN/IPUtils.h Diagnostic/VCI/Implementation/Elm327WLanVCI.cpp Diagnostic/VCI/Implementation/Elm327WLanVCI.h Diagnostic/Model/base/MsgSystem/Reponse.h Diagnostic/Model/base/MsgSystem/Request.h Diagnostic/Model/base/Command.h Diagnostic/Model/Implementation/Commands/AT/ATCommand.cpp Diagnostic/Model/Implementation/Commands/AT/ATCommand.h Diagnostic/Model/Implementation/Commands/ODB/OBDCommand.cpp Diagnostic/Model/Implementation/Commands/ODB/OBDCommand.h Diagnostic/Model/Implementation/ErrorMessages/Factory/ErrorMessageDef.h Diagnostic/Model/Implementation/ErrorMessages/Factory/ErrorMessageFactory.cpp Diagnostic/Model/Implementation/ErrorMessages/Factory/ErrorMessageFactory.h Orchestrator/ElmO.cpp Orchestrator/ElmO.h)

target_link_libraries(DiagnosticApp ${Boost_LIBRARIES})




