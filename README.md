# imgui-starter

Using the provided code provided here you have a base Dear IMGUI project for Windows and macOS. There is a basic CMakefile in this project that includes the necessary files to create an application that brings up just a basic screen.

You must add a logging system to this code that you will be using THROUGHOUT the quarter. This logging system should do two things.

It should be able to log to a Dear IMGUI debug console
It should also log its output to a file.

For the submission, make a branch of this repo and submit a new GitHub URL

# Approach

The approach I took to implementing this Logger was by using the Singleton design pattern.  The Logger is a singleton that would only be created once.  To do this, I would check to see if there was already an instance of the Logger.  If not, then I would create one.  The rest of the code was implemented by looking at the demo code to first replicate the look of the sample and then actually logging the message by using a .txt file and array.

# Questions

I didn't directly ask questions to the instructor, but I had similar questions on how Singletons work and should be implemented.  I also had many questions on how to use ImGUI which I found by messing around with the demo code.  Finally, I had some issues with getting the time and putting it correctly as a string, which I figured out by searching it up online.

# OS Used

Windows