#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

int main(){
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
    cin >> choice;
    
    while(choice != "E" && choice != "D"){
        cout << "Please only enter E or D\n";
        cin >> choice;
    }

    if(choice == "E"){

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
