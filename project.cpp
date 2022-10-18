//gamers sus
/****************************
 * Brainstorm:
 * AI script generator - comedy
 * Gabe's camera stuff
 * Gabe's drone stuff
 * Music writer
 * A video game about walkers and voyeurs (2 player pvp???)
 * 
 * 
*****************************/

#include <iostream>
#include <fstream> 
#include <cstdlib>  //necessary for the constant EXIT_FAILURE
#include <string>
#include <cmath>

using namespace std;

string fileToString (string);
string fileMadLib(int randNum, string filename);
int findThing(string file, string thing, int startInx);
string generateLib(string str);
string getRandWord (string file);
void combineCameraFiles(string camera1, string camera2, string camera3, string mainCamera);
//void addComma(string mainCamera);
/*


*/


int main()
{
  
  cout << endl << endl;
  srand(time(NULL));
  
  int randy = (rand() % 8) + 1; 

  //AddComma("cameraNoun.txt");
  string file = fileMadLib(randy, "madlibs.txt");
  
  combineCameraFiles("cameraNoun1.txt", "cameraNoun2.txt", "cameraNoun3.txt", "cameraNoun.txt");
  
  string finalFile = generateLib(file);
  cout << finalFile;
  cout << endl << endl;

  ofstream outputFile;
  outputFile.open("output.txt");
  outputFile << finalFile;
  outputFile.close();

  return 0;


}

/********************FUNCTIONS*********************/
string fileToString (string str) {

  ifstream fin;
 	fin.open(str);
 	//works
 	string result;
 	string current;
  //fin.peek() 
  //fin.get()
	
 	while (fin >> current) {
 		
 		result = result + current;
 		
 	}
 		
 		fin.close();
 		return result;
}

//Input name of file, outputs the word selected. Determines the number of words and selects a random one from them, as long as they're separated by commas.
string getRandWord (string file) {
  //cout << "Test 1:" << endl;                 //Testing
  int count = 1;
  int max = 0;
  string word = "";
  string garbage = "";

  
  ifstream inputFile;  //Opening input file
  
  inputFile.open(file);

  //Checking if file opened
  if (!inputFile.is_open()) {
    cout << "File failed to open in the getRandWord" << endl;
    return "ERR";
  }                                   
  //Getting the number of words
  while(!inputFile.eof()) {     
    //cout << "Test 2: " << max << endl;                        //Testing
    getline(inputFile, garbage);
    if (garbage == ",") {
      max++; 
      //cout << "Test 3: " << max << endl;                            //Testing
    }
  } 
  inputFile.close();
  
  /*******************
  //Charles's Code
  string str = fileToString(file);
  
  for (int x = 0; x < file.size(); x++) {

    if (str[x] == ',') {
      max++;
    }
    cout <<max <<endl;
    
  }
  
  if (max == 0) {
    max = 1;
    cout << "Max was 0, ERROR" << endl;
  }
  ****************/
  
  //Get random number
  srand(time(NULL) + (rand() % 100));
  int randNum = (rand() % max) + 1;
  
  //cout << "Test 3: " << randNum << endl;                              //Testing
  inputFile.open(file);
  
  //Getting the specific word in the file
  while(!inputFile.eof()) {
    if (count == randNum) {
      getline(inputFile, word);
      break;
    }
    else {
      getline(inputFile, garbage);
      if (garbage == ",") {
        count += 1;
      }
    }
  }
  
  inputFile.close();
  return word;
}

string generateLib(string str) {
  string ret = "";
  int stringLength = str.length();
  string startRandWord = getRandWord("cameraNoun.txt");

  ret = "This is a story about " + startRandWord + "\n";
  
  for (int x = 0; x < stringLength; x++) {

    
    if ((str[x] == '_') && (false == ((x + 2) > stringLength))) {

       if ((str[x + 1] == 'A') && (str[x + 2] == 'D')) {
        //adjetive
        string randWord = getRandWord("Adjective.txt");
        ret.append(randWord);
        x = x + 11;
       }
       if ((str[x + 1] == 'N') && (str[x + 2] == 'A') && (str[x + 3] == 'M')) {
        //name
        string randWord = getRandWord("Names.txt");
        ret.append(randWord);
        x = x + 6;
       }
       if ((str[x + 1] == 'E') && (str[x + 2] == 'D')) {
        //verb ending in ed
        string randWord = getRandWord("Ed.txt");
        ret.append(randWord);
        x = x + 4;
       } 
       if ((str[x + 1] == 'B') && (str[x + 2] == 'O')) {
        //body part
        string randWord = getRandWord("Body_parts.txt");
        ret.append(randWord);
        x = x + 11;
       }
       if ((str[x + 1] == 'N') && (str[x + 2] == 'O') && (str[x + 3] == 'U')) {
        //noun
        string randWord = getRandWord("cameraNoun.txt");
        ret.append(randWord);
        x = x + 6;
       } 
       if ((str[x + 1] == 'V') && (str[x + 2] == 'E')) {
        //verb
        string randWord = getRandWord("Verbs.txt");
        ret.append(randWord);  
        x = x + 6;
       }
       if ((str[x + 1] == 'P') && (str[x + 2] == 'L')) {
        //place
        string randWord = getRandWord("Places.txt");
        ret.append(randWord);
        x = x + 7;
       }     
       if ((str[x + 1] == 'N') && (str[x + 2] == 'U')) {
        //number 
        srand(x);
        string randWord = to_string((rand() % 100) + 1);
        ret.append(randWord);
        x = x + 8;
       } 
       if ((str[x + 1] == 'A') && (str[x + 2] == 'N')) {
        //animal
        string randWord = getRandWord("Animals.txt");
        ret.append(randWord);
        x = x + 8;
       } 
       if ((str[x + 1] == 'N') && (str[x + 2] == 'O') && (str[x + 3] == 'I')) {
        //noise
        string randWord = getRandWord("noise.txt");
        ret.append(randWord);
        x = x + 7;
       } 
       if ((str[x + 1] == 'L') && (str[x + 2] == 'I')) {
        //liquid
        string randWord = getRandWord("Liquid.txt");
        ret.append(randWord);
        x = x + 8;
       } 
       if ((str[x + 1] == 'O') && (str[x + 2] == 'C')) {
        //occcuaption
        string randWord = getRandWord("Ocupations.txt");
        ret.append(randWord);
        x = x + 12;
       } 

         
     }
     ret.append(1, (str[x]));

    
  
  }

  return ret;
}

//Input random number, will pull out the specific MadLib for that number. Requires the random number, 1-max mad lib and the . Returns "ERR" if failed.
string fileMadLib(int randNum, string filename) {

  int count = 1;
  ifstream inputFile;
  inputFile.open(filename);
  
  string madlib = "";
  string garbage = "";
  
  //Checking if file opened
  if (!inputFile.is_open()) {
    cout << "File failed to open in the fileMadLib function" << endl;
    return "ERR";
  }

  while(!inputFile.eof()) {
    //if the paragraph is not the one we want, skip to next one
    if (!(count == randNum)) {
      getline(inputFile, garbage);
      if (garbage == "|") {
        count++;
      }
    }
    //if the paragraph is the one we want, input the paragraph into a string
    else if (count == randNum) {
      getline(inputFile, garbage);
      if (garbage == "|") {
        count++;
        continue;
        //exits this else if statement, goes back to while loop
      }
      
      madlib = madlib.append(garbage + "\n"); 
      
    }
    
  }

  inputFile.close();
  return madlib;
}


void combineCameraFiles(string camera1, string camera2, string camera3, string mainCamera) {
  string cam1 = fileToString(camera1);
  string cam2 = fileToString(camera2);
  string cam3 = fileToString(camera3);

  string ret = cam1 + "\n,\n" + cam2 + "\n,\n" + cam3 + "\n,";
  cout << cam1 << " " << cam2 << " " << cam3 << " " << " RESULT: " << endl << endl << ret << endl << endl;
  //Puts big string into the mainCamera output File, also returns it just in case.
  ofstream outputFile;
  outputFile.open(mainCamera);
  
  outputFile << ret;
  outputFile.close();

}

/*
void addComma(string mainCamera) {

  string ret = fileToString(mainCamera) + "\n,";
  //Puts big string into the mainCamera output File, also returns it just in case.
  ofstream outputFile;
  outputFile.open(mainCamera);
  
  outputFile << ret;
  outputFile.close();
}
*/


//WOOOOOOOO C++ BABY