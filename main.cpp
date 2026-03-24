#include <iostream>
#include <vector>
#include <cctype>
#include <ctime>
#include <string>

using namespace std;

int main(){
    unsigned long previousRandom = 1;
    //time_t is the type that time returns
    const time_t CURRENTTIME = time(0);

    const string ENCRYPTEDTEXT = "TJXUN LWWTK VULPY EIPXB ADYMP TXNEY DGOPL "
    "QHLEC VGKNO ZCGGK GUTPL LYVAC NRTRC CGXOH SYTGO YRHPI NQPBO "
    "HEMOT WYRTE RORXL FZCKI VVUNQ ZJLQP UNLWW SKLVU ETRHC LHOAZ UETHZ AYEGC KIUTT " 
    "YEAPR UNLWW TKVUL CPJAV BINDZ PTTNN HDTRS RKIVT YAEKL NOLDQ IUMOS TYKAM BHGLG YINTV "
    "LPHFA VPYAC PYLTX UDJLA QWTCN EPBWK MBTSP YNCES TTNYL GGAIY PUECO YSLWE EDKUI NAYTV XLNDU "
    "SSVTM TSPHA EJOAC OJOQF QELGC SHEIW PCQAP WFELG CS";
    
    /* 93 possible keys */
    vector<string> keys = {"receipt", "vengeful" , "popcorn", "basketball", "friends", "wealth", "interrupt",
    "awesome", "actually", "kindhearted", "nifty", "change", "heat", "squeal", "treatment", "satisfy", "separate", "hot", "serious", 
    "pail", "request", "different", "righteous", "cat", "cheap", "repair", "uncle", "creepy", "birds", "crook", "great",
    "ski", "stitch", "example", "flippant", "puzzling", "sleepy", "discover", "excuse", "unbiased", "jail", "eggs", "material",
    "expand", "equal", "group", "bizzare", "spotted", "embarrass", "produce", "womanly", "spectacular", "agonizing", "cows", "suck", 
    "ritzy", "hole", "sail", "dam", "seperate", "fumbling", "mushy", "unite", "economic", "clean", "auspicious", "beds", "sweltering", 
    "crazy", "wise", "unknown", "adorable", "versed", "supreme", "store", "tour", "substantial", "record", "impolite", "birth", "tender", 
    "unequal", "line", "connection", "shade", "nervous", "attraction", "argue", "finger", "carriage", "destruction", "afterthought", "stick"};
    
    string choice;

    cout << "Would you like to decrypt the text(D) or encrypt your own(E). Please only enter E or D\n";
    getline(cin, choice);
    
    while(choice != "E" && choice != "D"){
        cout << "Please only enter E or D\n";
        getline(cin, choice);
    }


    //Generates a random number with the current time as a seed. Then uses that random number to get a swap
    //distance to swap the letters in the text. Then loops through each letter in that word and creates another random 
    //number to get a letter shift to preform a Caesar Cipher on that letter and repeat until the loop ends
    if(choice == "E"){
        vector<int> letterShifts;
        unsigned long swapDistance;
        int letterShift;
        string text;
        string answerText = "";
        cout << "Enter the text you wish to encrypt: \n";
        getline(cin, text);
        
        //a "random" number seeded with the current time(no large multiplications since I don't want int overflow)
        unsigned long currentRandom = (178902325 + (CURRENTTIME * previousRandom) + previousRandom) / 95;
        previousRandom = currentRandom;

        if(text.size() > 1){
            swapDistance = currentRandom % (text.size());
        }
        else{
            //if the text is just a letter there are no possible swaps
            swapDistance = 0;
        }

        //swap every letter according to the index swapDistance spaces and symbols are ignored
        //One iteration for swapping letters in Hello with a shift of one is eHllo
        for(int i = 0; i < text.size(); i++){
            int shiftIndex = (i + swapDistance) % text.size();
            char temp = text.at(i);

            if(isalpha(temp) && isalpha(text.at(shiftIndex))){
                text.at(i) = text.at(shiftIndex);
                text.at(shiftIndex) = temp;
            }
        }

        //one time pad part of the encryption since each shift is "random"
        for(int i = 0; i < text.size(); i++){
            //no point in getting a shift if it is not a letter
            if(!isalpha(text.at(i))){
                answerText += text.at(i);
                continue;
            }

            //"call" random upon each iteration
            currentRandom = (178902325 + (CURRENTTIME * previousRandom) + previousRandom) / 95;
            previousRandom = currentRandom;

            letterShift = currentRandom % 26;
            letterShifts.push_back(letterShift);

            if(isupper(text.at(i))){
                answerText += (((text.at(i) - 'A') + letterShift) % 26) + 'A';
            }
            else{
                answerText += (((text.at(i) - 'a') + letterShift) % 26) + 'a';
            }
        }

        //print all the shifts used so someone receiving can decrypt
        cout << "Your encrypted text is: " << answerText << "\n";
        cout << "The letter swap distance was: " << swapDistance << "\n";

        if(letterShifts.size() > 0){
            cout << "Letter shifts used: \n";

            if(letterShifts.size() > 20){
                string seeOrNo;
                cout << "WARNING! " << letterShifts.size() << " shifts were used are you sure you want to see all of them?(Y/N)\n";
                getline(cin, seeOrNo);

                while(seeOrNo != "Y" && seeOrNo != "N"){
                    cout << "Please only enter Y or N\n";
                    getline(cin, seeOrNo);
                }

                if(seeOrNo == "Y"){
                    for(int i = 0; i < letterShifts.size(); i++){
                        cout << letterShifts.at(i) << "\n";
                    }
                }
            }
        }
        else{
            cout << "Text is either all symbols or empty so no letter shifts were used\n";
        }
    }
    else{
        vector<double> occurrences(26, 0);
        cout << "\nFrequency Analysis: \n";

        for(int i = 0; i < ENCRYPTEDTEXT.size(); i++){
            char letter = ENCRYPTEDTEXT.at(i);
            if(isalpha(letter)){
                occurrences.at(letter - 65)++;
            }
        }

        for(int i = 0; i < occurrences.size(); i++){
            char a = i + 65;
            cout << a << " : " << (occurrences.at(i) / ENCRYPTEDTEXT.size()) * 100 << "%\n";
        }
        //We would preferably sleep the thread for like 5 seconds but I have to ask the professor on Wednesday 
        //if I can include the appropiate header file
        
        int counter = 0; //to skip the spaces in encrypted text

        for (unsigned int i = 0; i < keys.size(); i++){ //Iterate though the keys
            cout << keys.at(i) << ": ";
            //key is actually
            for (unsigned int j = 0; j < ENCRYPTEDTEXT.length(); j++){ //Iterate throught the encrypted text
                if (isalpha(ENCRYPTEDTEXT.at(j))) { //Check if it is a letter
                    int k = counter % keys.at(i).length(); //Get the shift letter
                    char c = ENCRYPTEDTEXT.at(j) - 65; //Convert to 0-25
                    c = ((c - (keys.at(i).at(k) - 97) + 26) % 26) + 65; //Get the decrypted letter

                    counter++;
                    cout << c; //Print the decrypted letter
                    
                }
                else {
                    cout << " "; //Print the space
                }
            }
            
            cout << endl << endl;
        }
    }

    return 0;
}
