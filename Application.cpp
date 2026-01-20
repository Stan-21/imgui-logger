#include "Application.h"
#include "imgui/imgui.h"
#include "Logger.h"

/*
    I made a Logger.cpp and Logger.h file to create the Logger class.  I also added a few lines
    in Application.cpp to render the Logger.  To use this Logger, click on the test buttons to 
    see info, warning, and error logs.  To switch between different levels of logging, click on
    the options button which cycle through (all, warning + error, and only errors).  Finally, there
    is a clear button which clears the log in ImGUI, but still leaves everything in the text file, with
    a line that says everything cleared.  I decided to do this because the text file would have a record
    of everything and the clear button could also be used as a breakpoint for easier debugging.

*/

namespace ClassGame {
        //
        // our global variables
        //

        //
        // game starting point
        // this is called by the main render loop in main.cpp
        //
        void GameStartUp() 
        {
            // Initialize logging system
            Logger& logger = Logger::GetInstance();
            logger.LogInfo("Game started successfully");
            logger.LogGameEvent("Application initialized");
        }

        //
        // game render loop
        // this is called by the main render loop in main.cpp
        //
        void RenderGame() 
        {
            Logger& logger = Logger::GetInstance();
            logger.Render();
            
            ImGui::DockSpaceOverViewport();
            ImGui::ShowDemoWindow();

            ImGui::Begin("ImGui Log Demo");
            ImGui::LogButtons();

            if (ImGui::Button("Copy \"Hello, world!\" to clipboard"))
            {
                ImGui::LogToClipboard();
                ImGui::LogText("Hello, world!");
                ImGui::LogFinish();
            }
            ImGui::End();
        }

        //
        // end turn is called by the game code at the end of each turn
        // this is where we check for a winner
        //
        void EndOfTurn() 
        {
        }
}
