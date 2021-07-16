#include<iostream>
#include<dirent.h>
#include<string>
#include<Windows.h>
#include<mmsystem.h>
#include<time.h>
#include"AudioPlayer.h"
using namespace std;
AudioPlayer::AudioPlayer()
{
	currentdir = "";
	pno = 0;
	currentpno = 0;
	for (int i = 0; i < 5; i++)
	{
		p[i] = NULL;
	}
}
AudioPlayer::~AudioPlayer()
{
	int i = 0;
	while(p[i] != NULL)
	{
		cout << "Destructore called\n";
		p[i]->list.~LinkedList();
		p[i] = NULL;
		i++;
    }
}
void AudioPlayer::selectDir(string directory)
{
	if (directory == "")
	{
		cout << "Set Directory: ";
		cin.clear();
		cin.ignore();
		getline(cin, directory);
		currentdir = directory;
	}
	else
	currentdir = directory;
}
void AudioPlayer::changeDir(string newdir)
{
	if (currentdir != "")
	{
		if (newdir == "")
		{
			cout << "Set Directory: ";
			getline(cin, newdir);
			currentdir = newdir;
		}
		else
		{
			currentdir = newdir;
		}
	}
	else
		cout << "No directory selected. First select dir and then try again!\n";
}
bool AudioPlayer::showcurrentDir(string audio)
{
	DIR* dir;
	struct dirent* pdir;
	do
	{
		dir = opendir(currentdir.c_str());
		if (dir == NULL)
		{
			cout << "Error! Directory not set properly. Please set again.\n";
			selectDir();
		}
	}	while (dir == NULL);
	do
	{
		pdir = readdir(dir);
		if (pdir != NULL)
		{
			if ( audio == "")
			cout << pdir->d_name << "\t";
			else if (pdir->d_name == audio)
				return true;
		}
	} while (pdir != NULL);
	cout << endl;
	return false;
}
void AudioPlayer::createPlaylist(string name)
{
	if (!isPlayAvailable(name))
	{
		if (pno >= 5)
		{
			cout << "Max of 5 playlists can be created!\n";
		}
		else
		{
			p[pno] = new PlayList;
			p[pno]->name = name;
			cout << "Playlist " << name << " is succesfully created\n";
			pno++;

		}
	}
	else
	{
		cout << "ERROR! Playlist: " << p[currentpno]->name << " already exists!\n";
	}
}
bool AudioPlayer::isPlayAvailable(string playname)
{
	for (int i = 0; i < 5; i++)
	{
		if (p[i] != NULL)
		{
			if (p[i]->name == playname)
			{
				currentpno = i;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}
bool AudioPlayer::isAudioAvailable(string playname, string audio, int* pos)
{
	bool avail = false;
	if (isPlayAvailable(playname))
	{
		if (!p[currentpno]->list.isEmpty())
		{
			int size = p[currentpno]->list.findLength();
			string* audioarr = new string[size];
			audioarr = p[currentpno]->list.getData();
			string subaudio;
			
			for (int i = 0; i < size; i++)
			{
				string audio1 = audioarr[i];
				reverse(audio1.begin(), audio1.end());
				int pos1 = audio1.find('\\');
				subaudio = audio1.substr(0, pos1);
				reverse(subaudio.begin(), subaudio.end());
				if (subaudio == audio)
				{
					if ( pos != 0)
					*pos = ++i;
					avail = true;
				}
			}
			delete[] audioarr;
			audioarr = NULL;
		}
	}
	else
	{
		cout << "Invalid Playlist!\n";
	}
	return avail;
}
void AudioPlayer::insertAudio(string playname, string audio)
{
	if (isPlayAvailable(playname))
	{
		if (showcurrentDir(audio))
		{
			if (!isAudioAvailable(playname, audio))
			{
				string audiofile = currentdir + "\\" + audio;
				p[currentpno]->list.insertAtEnd(audiofile);
				cout << "Audio: " << audio << " successfully added to the Playlist " << p[currentpno]->name << endl;
			}
			else
			{
				cout << "Audio: " << audio << " is already in the playlist: " << p[currentpno]->name << endl;
			}
		}
		else
		{
			cout << "Audio file does not exist!";
		}
	} 
	else
	{
		cout << "Playlist does not exist!\n";
	}
	
}
void AudioPlayer::play(string playname)
{
	if (isPlayAvailable(playname))
	{
		if (!p[currentpno]->list.isEmpty())
		{
			int size = p[currentpno]->list.findLength();
			string* audioarr = new string[size];
			audioarr = p[currentpno]->list.getData();
			for (int i = 0; i < size; i++)
			{

				wstring audio = wstring(audioarr[i].begin(), audioarr[i].end());
				wchar_t* audioc = _wcsdup(audio.c_str());
				wcout << audioc << " is playing......" << endl;
				PlaySound(audioc, NULL, SND_SYNC);
			}
			delete[] audioarr;
			audioarr = NULL;
		}
		else
		{
			cout << "No Audio to play. Playlist: " << p[currentpno]->name << " is empty!\n";
		}
	}
	else
	{
		cout << "No such Playlist available to play!\n";
	}
}
void AudioPlayer::deleteAudio(string playname, string audio)
{
	if (isPlayAvailable(playname))
	{
		if (!p[currentpno]->list.isEmpty())
		{
			int pos = 0;
			if (isAudioAvailable(playname, audio, &pos))
			{
				p[currentpno]->list.deleteAtAnyPos(pos);
				cout << "Audio: " << audio << " successfully deleted.\n";
			}
			else
			{
				cout << "Audio: " << audio << " does not exist in playlist " << p[currentpno]->name << endl;
			}
		}
		else
		{
			cout << "Playlist: " << p[currentpno]->name << " is empty. No audio to delete!\n";
		}

	}
	else
	{
		cout << "No Playlist to play!\n";
	}
}
void AudioPlayer::shufflePlayList(string playname)
{
	if (isPlayAvailable(playname))
	{
		if (!p[currentpno]->list.isEmpty())
		{
			int size = p[currentpno]->list.findLength();
			string* audioarr = new string[size];
			size = size - 1;
			audioarr = p[currentpno]->list.getData();
			srand(time(0));
			for (int i = size; i > 0; i--)
			{
				int j = rand() % (i + 1);
				swap(audioarr[i], audioarr[j]);
			}
			size = size + 1;
			p[currentpno]->list.~LinkedList();
			string name = p[currentpno]->name;
			p[currentpno] = new PlayList;
			p[currentpno]->name = name;
			for (int i = 0; i < size; i++)
			{
				p[currentpno]->list.insertAtEnd(audioarr[i]);
			}
			delete[] audioarr;
			audioarr = NULL;
		}
		else
		{
			cout << "Playlist: " << p[currentpno]->name << " is empty. Nothing to shuffle!\n";
		}
	}
	else
	{
		cout << "Playlist does not exist!\n";
	}
}