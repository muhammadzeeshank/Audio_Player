#include<iostream>
#include<string>
#include"AudioPlayer.h"
using namespace std;
void main()
{
	AudioPlayer obj;
	string playname;
	string audioname;
	cout << "--------------------------\n";
	cout << "****** Audio Player ******\n";
	cout << "--------------------------\n";
	cout << endl;
	string directory;
	cout << "Set Directory: ";
	getline(cin, directory);
	
	obj.selectDir(directory);
	int option;
	do {
		cout << "***Select Option*** \n";
		cout << "1: Change Directory\n";
		cout << "2: Show Audio files in current Directory\n";
		cout << "3: Create new playlist\n";
		cout << "4: Insert an Audio File in play list\n";
		cout << "5: Delete an Audio from play list\n";
		cout << "6: Shuffle Playlist\n";
		cout << "7: Play the play list\n";
		cout << "8: Exit!\n";
		
		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			option = 0;
		}
		switch (option) {
		case 1:
			cout << "Set Directory: ";
			cin.ignore(256, '\n');
			getline(cin, directory);
			obj.changeDir(directory);
			break;
		case 2:
			obj.showcurrentDir();
			break;
		case 3:
			cout << "Enter playlist name: ";
			cin >> playname;
			obj.createPlaylist(playname);
			break;
		case 4:
			cout << "Enter Audio name: ";
			cin >> audioname;
			cout << "Enter playlist name: ";
			cin >> playname;
			obj.insertAudio(playname, audioname);
			break;
		case 5:
			cout << "Enter Audio name: ";
			cin >> audioname;
			cout << "Enter playlist name: ";
			cin >> playname;
			obj.deleteAudio(playname, audioname);
			break;
		case 6:
			cout << "Enter playlist name: ";
			cin >> playname;
			obj.shufflePlayList(playname);
			break;
		case 7:
			cout << "Enter playlist name: ";
			cin >> playname;
			obj.play(playname);
			break;
		case 8:
			break;
		default:
			cout << "Enter Correct choice!\n";
			break;
		}
	} while (option != 8);
}