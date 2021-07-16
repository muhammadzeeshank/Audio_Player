#include"LinkedList.h"
struct PlayList
{
	std::string name;
	LinkedList<string> list;
};
class AudioPlayer
{
	PlayList* p[5];
	std::string currentdir;
	int pno, currentpno;
public:
	AudioPlayer();
	~AudioPlayer();
	void selectDir(string directory = "");
	void changeDir(string newdir = "");
	bool showcurrentDir(string audio = "");
	void createPlaylist(string name);
	void insertAudio(string playname, string audio);
	bool isPlayAvailable(string playname);
	bool isAudioAvailable(string playname, string audio, int* pos = 0);
	void play(string playname);
	void deleteAudio(string playname, string audio);
	void shufflePlayList(string playname);
};
