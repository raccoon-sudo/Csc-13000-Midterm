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
    "SSVTM TSPHA EJOAC OJOQF QELGC SHEIW PCQAP WFELG CS"; //shouldn't this be a vector, or is it fine as a string

    string choice;
    /* We probably do not need to write all 96 keys into a vector so I stopped at the 55 item(suck)
    vector<string> keys = {"receipt", "vengeful" , "popcorn", "basketball", "friends", "wealth", "interrupt",
    "awesome", "actually", "kindhearted", "nifty", "change", "heat", "squeal", "treatment", "satisfy", "separate", "hot", "serious", 
    "pail", "request", "request", "different", "righteous", "cat", "cheap", "repair", "uncle", "creepy", "birds", "crook", "great",
    "ski", "stitch", "example", "flippant", "puzzling", "sleepy", "discover", "excuse", "unbiased", "jail", "eggs", "material",
    "expand", "equal", "group", "bizzare", "spotted", "embarrass", "produce", "womanly", "spectacular", "agonizing", "cows", "suck"};
    */

    cout << "Would you like to decrypt the text(D) or encrypt your own(E). Please only enter E or D\n";
    getline(cin , choice);


    if(choice == "E"){

    }
    else{

    }

    return 0;
}
