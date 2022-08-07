#ifndef _history_
#define _history_

#ifndef _predef_h_
#   include "npredef.h"
#endif

#ifndef _trig_h_
#   include "ntrig.h"
#endif

#ifndef _i_trig_h_
#   include "ninvtrig.h"
#endif

#ifndef _history_classes_
#   define _history_classes_

class history {
public:
   string overall[300];
   string coeffY[10];
   string coeffX[10];
   string arg[10];
};

class historyTextFile : public history {
private:
   string write[300];
   string read[400];

public:
   void fileCheck();
   void writeToFile(history);
   void readFromFile();
};

void
historyTextFile::fileCheck() {
   fstream historyFile("history.txt", ios::out | ios::noreplace);

   if ( ! historyFile ) {
      remove("history.txt");

      fstream historyFile("history.txt", ios::out | ios::trunc);
      historyFile << "Graphs Printed: " << endl;
   }

   historyFile.close();
}

void
historyTextFile::writeToFile(history h) {
   strcpy(write, h.overall);
   fstream historyFile("history.txt", ios::out | ios::app);
   historyFile << write;
   historyFile.close();
}

void
historyTextFile::readFromFile() {
   fstream historyFile("history.txt", ios::in);
   historyFile.getline(read, 400);

   while ( ! historyFile.eof() ) {
      cout << read << endl;
      historyFile.getline(read, 400);
   }

   historyFile.close();
}

#endif

#endif