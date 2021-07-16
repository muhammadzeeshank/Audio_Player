# Audio_Player
A console App with functionalities like playing audios, creating playlists etc.
</br>
<h2>Functionalities</h2>
<p>This Audio Player has following functionalities:</p>
<ul>
  <li><b>Change current directory:</b> User can change the current directory. in that case your existing play list (if any) will be destroyed.</li>
  <li><b>Create a new play list:</b> If user selects option to create a new playlist, your program should ask the user to create an empty play list.</li>
  <li><b>Insert an Audio File in play list:</b> If user wants to insert an audio file to his play list, he can choose it from current directory ONLY. Your application should insert the audio file at end of existing linked list.</li>
  <li><b>Delete an Audio from play list:</b> User may delete any audio file from playlist. Audio file shouldn’t be deleted from directory.</li>
  <li><b>Shuffle Playlist:</b> Play list gets shuffled in random order once user selects shuffle option.</li>
  <li><b>Play the play list:</b> Play all audio files from start to end present in play list created by user.</li>
</ul>
<p><em>Note:</em> An instance of Audio player can ONLY hold 5 play lists. Each playlist can be identified from its name and its directory. A playlist can ONLY hold songs from same directory.</p>

<h2>External Resources</h2>
<p><b>dirent.h</b> is a header file that is found only on Linux systems. It provides data structures and function calls to open and read the contents of directories. If you are trying to port Linux code that uses this header file to Windows, you will that it is not available with Visual Studio.</p>
<p>There is a Windows implementation of **dirent.h** which can be downloaded <a href="https://github.com/tronkko/dirent">here</a> on Github. Just download the zip file, find the **dirent.h** header file and place it in your Visual Studio include directory. </p>
