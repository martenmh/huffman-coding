#include <iostream>

// Huffman coding:
// each character is 8 bit
// 256 possible characters
// count how much each character is used and put it in a list in order
// two least used characters are the base of the Huffman tree
// connect them with the sum of the frequency
// when a single character is used as many times as the sum of the lower frequency connect them with the sum all three 1 1 > 2 - 2 2 > 4

// navigating the tree:
// each time you take the left side put a 0
// each time you take the right side put a 1
// save it as the stream of bits

// when uncompressing do the same

#include "HuffmanTree.h"
#include "HuffmanList.h"
#include <fstream>
#include <string>

int main(int argc, char **argv) {
    // TODO: RAII class
    //std::ifstream myfile;

    //myfile.open (argv[1]);

//    std::string str((std::istreambuf_iterator<char>(myfile)),
//                    std::istreambuf_iterator<char>());
    //myfile.close();
    std::string str = "Wild Wild West\n"
                      "Wild Wild West, Jim West, desperado, rough rider\n"
                      "No you don't want nada\n"
                      "None of this, gun in this, brotha runnin this,\n"
                      "Buffalo soldier, look it's like I told ya\n"
                      "Any damsel that's in distress\n"
                      "Be out of that dress when she meet Jim West\n"
                      "Rough neck so go check the law and abide\n"
                      "Watch your step with flex and get a hole in your side\n"
                      "Swallow your pride, don't let your lip react,\n"
                      "You don't wanna see my hand where my hip be at,\n"
                      "With all of this, from the start of this,\n"
                      "Runnin the game, James West tamin the west so remember the name\n"
                      "Now who ya gonna call?\n"
                      "Not the G.B.'s\n"
                      "Now who you gonna call?\n"
                      "If you have a riff with people wanna bust,\n"
                      "Break out before you get bumrushed at the (Wild Wild West)\n"
                      "When I roll into the (Wild Wild West)\n"
                      "When I stroll into the (Wild Wild West)\n"
                      "When I bounce into the (Wild Wild West) Sisqo, Sisqo\n"
                      "We going straight to the Wild Wild West\n"
                      "We going straight to the Wild Wild West\n"
                      "Now, now, now, now once upon a time in the west\n"
                      "Mad man lost his damn mind in the west\n"
                      "Loveless, givin up a dime, nothin' less\n"
                      "Now I must put his behind to the test (can you feel me)\n"
                      "Then through the shadows, in the saddle, ready for battle\n"
                      "Bring all your boys in, here come the poison\n"
                      "Behind my back, all the riffin' ya did,\n"
                      "Front and center, now where your lip at kid?\n"
                      "Who dat is? A mean brotha, bad for your health\n"
                      "Lookin damn good though, if I could say it myself\n"
                      "Told me Loveless is a mad man, but I don't fear that\n"
                      "Got mad weapons too, ain't tryin to hear that\n"
                      "Tryin to bring down me, this champion\n"
                      "When y'all clowns gon' see that it can't be done\n"
                      "Understand me son, I'm the slickest they is,\n"
                      "I'm the quickest as they is, did I say I'm the slickest they is\n"
                      "So if you barking up the wrong tree we comin, don't be startin nothin\n"
                      "Me and my partner gonna test your chest, Loveless\n"
                      "Can't stand the heat then get out the Wild Wild West\n"
                      "We going straight to (when I roll into the) the Wild Wild West (when I stroll into the)\n"
                      "We going straight to (when I bounce into the) the Wild Wild West\n"
                      "We going straight to the Wild Wild West\n"
                      "We going straight to the Wild Wild West\n"
                      "To any outlaw tryin to draw, thinkin you're bad,\n"
                      "Any draw on West best with a pen and a pad,\n"
                      "Don't even think about it, six gun, weighin a ton,\n"
                      "10 paces and turn, just for fun, son,\n"
                      "Up till sundown, rolling around,\n"
                      "See where the bad guys are to be found and make 'em lay down,\n"
                      "The defenders of the west,\n"
                      "Crushin on pretenders in the west,\n"
                      "Don't mess with us cuz we're in the (Wild Wild West)\n"
                      "We going straight to the Wild Wild West\n"
                      "We going straight to the Wild Wild West\n"
                      "We going straight to the Wild Wild West\n"
                      "We going straight to the Wild Wild West\n"
                      "We going straight to the Wild Wild West\n"
                      "We going straight to the Wild Wild West, come on\n"
                      "When I roll into the\n"
                      "(Wild Wild West)\n"
                      "When I stroll into the\n"
                      "We going straight to the Wild Wild West (the Wild Wild West)\n"
                      "(Wild, Wild West) whoo, uh\n"
                      "(Wild Wild West) ha ha ha ha\n"
                      "(Wild Wild West) uh Dru, Dru\n"
                      "(Wild Wild West) I done done it again y'all done done it again\n"
                      "(Wild Wild West) ha ha ha ha\n"
                      "(Wild Wild West) Big Will, Dru Hill, uh\n"
                      "(Wild Wild West) Big Will, Dru Hill ha ha ha ha\n"
                      "(Wild Wild West) the Wild Wild West\n"
                      "(Wild Wild West) uh\n"
                      "(Wild Wild West) one time\n"
                      "(Wild Wild West) uh,\n"
                      "(Wild Wild West) the wild wild west bring in the heat, bring in the heat, what?\n"
                      "(Wild Wild West)\n"
                      "(Wild Wild West) uh can't stop the bumrush\n"
                      "The Wild Wild (the Wild Wild West)";
    HuffmanTree tree = HuffmanTree(str);
    return 0;
}