#include<iostream.h>
#include<process.h>

/*************************************************************/

typedef char string;

/*************************************************************/

class myFolder {
	private:
		string fileName[10][25];
		int fileIndex;
		long int totSpace;
		long int usedSpace;

	public:
		void folderInit(long int);
		void newEntry();
		void showFiles();
		long int retSpace();
};

/*************************************************************/

inline void myFolder::folderInit(long int totalSpace) {
	totSpace = totalSpace;
	fileIndex = 0;
	usedSpace = 0;
}

/*************************************************************/

inline void myFolder::newEntry() {
	int fileSize = 0;

	cout << endl << "Enter file size (in bytes): ";
	cin >> fileSize;

	if (usedSpace + fileSize > totSpace) {
		cout << "Folder full." << endl;
		return;
	} else {
		usedSpace += fileSize;
	}

	cout << "Enter file name: ";
	cin >> fileName[fileIndex];
	fileIndex++;
}

/*************************************************************/

void myFolder::showFiles() {
	cout << endl << "List of files: " << endl;

	for (int i = 0; i < fileIndex; i++) {
		cout << i + 1 << ". " << fileName[i] << endl;
	}

}

/*************************************************************/

inline long int myFolder::retSpace() {
	long int availableSpace = totSpace - usedSpace;
	return availableSpace;
}

/*************************************************************/

long count = 0;

/*************************************************************/

int main(void) {
	int rep = 1;

	while (rep == 1) {
		system("cls");

		int choice;

		long int totalSpace;
		cout << "Enter the total size of the folder (in bytes): ";
		cin >> totalSpace;

		myFolder folder;
		folder.folderInit(totalSpace);

		folder.newEntry();

		choiceLocation:
		cout << endl << "1. Enter new files" << endl;
		cout << "2. Display all file names" << endl;
		cout << "3. Display value of space left" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				folder.newEntry();
				goto choiceLocation;
				break;

			case 2:
				folder.showFiles();
				goto choiceLocation;
				break;

			case 3:
				cout << endl << "Folder has " << folder.retSpace() << " bytes left" << endl;
				goto choiceLocation;
				break;

			case 4:
				exit(0);

			default:
				cout << "Wrong Choice" << endl;
				goto choiceLocation;
				break;
		}

		cout << endl << endl << "Repeat Program?" << endl;
		cin >> rep;
		count++;

		if (count >= 50) {
			system("cls");

			cout << "Abnormal END" << endl;

			system("pause");
			exit(0);
		}

	}

	cout << "Normal END" << endl;

	system("pause");
	return 0;
}