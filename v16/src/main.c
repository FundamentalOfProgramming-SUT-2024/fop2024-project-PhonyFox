#include "rogue.h"

int main ()
{
    screenSetUp();

    SDL_Init(SDL_INIT_AUDIO);
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    play_or_replace_music("music1.mp3");
    setlocale(LC_ALL, "");
    curs_set(0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_RED, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
    /*
    attron(COLOR_PAIR(6));
    attron(A_BOLD);
    for (int i = 0; i < 70; i++)
{
    mvprintw(0, 0, " ");
    printw("                                     =++========+===---=-\n");
    printw("                                   :=-.:::-:.   :.......  .+:\n");
    printw("                                   *   .   .    ::-==-:..   -:\n");
    printw("                                 =+:.  =*##%%*  .%%+-%%**-.:---++:\n");
    printw("                                 #:--=-=- .*:   .   :=---+*.-+:==\n");
    printw("                                 *=::%% .-%%:  -=+# .:-+*-.++-%%:-+\n");
    printw("                                 .# #@%%+-..=*::-=*#=-:+#+#+  :+=\n");
    printw("                                  # #%%#=#:-@==@:.-%%**+*#+=   *-\n");
    printw("                                  # =%%@@%%@%%####=::+ -==   :=\n");
    printw("                                  %%  -+**%%=+=::*---==: .:==.\n");
    printw("                         -*###%%##%% . :::...... . .:-===\n");
    printw("                          -+##+=:.#- .......   .:-==:\n");
    printw("                             .+@@* -==-:::=-===%%@@:\n");
    printw("                               .-         ..   =@@%%.\n");
    printw("                                         #@@+  .@%%@+\n");
    printw("                                         -%%@-   +#%%\n");
    printw("                                           +%%+: :@:@=\n");
    printw("                                            .+%%#+@ +%%\n");
    printw("                                               =@@=.@:\n");
    printw("                                               .@**@@+\n");
    printw("                            ##*=.              +@.  :.\n");
    printw("                            *@=+#%%#+-.         @*\n");
    printw("                            :@-   :=*%%#+-.   +@.\n");
    printw("                           .-@*        -+%%@%%+=@*\n");
    printw("                          :%%@@#           .=#@@:\n");
    printw("                                              %%+\n");
    printw("                                              =@.\n");
    printw("                                               @*\n");
    printw("                                               *@\n");
    printw("                                               -@-\n");
    printw("                                               +@=\n");
    printw("                                               #@:\n");
    printw("                                              :@%%\n");
    printw("                                              *@+\n");
    printw("                                             :@@.\n");
    printw("                                             #@*\n");
    printw("                                             *%%%%@@@=\n");

    refresh();
    napms(100);
    refresh();
    clear();

    mvprintw(0, 0, " ");
    printw("                                    :-===========-::--:\n");
    printw("                                   :====-:...  ..::::..  .+-\n");
    printw("                                  :+  ..  .:   .. ... .:   --\n");
    printw("                                 -+:. .*#*+=.  -==#@@@*..  .=+:\n");
    printw("                                ++:=-=:.. :%%:  .=:.:+=---++==:++\n");
    printw("                                =*: -+.-.=#:  .:=- . .-===#-==:*.\n");
    printw("                                 *::@@+:.:==-.=--+===+%%--*= :-==\n");
    printw("                                 :=:@+*+=:=+=*+--+*=+*@++=   #-\n");
    printw("                                 .+.@@@@%%#%%@%%@@*++%%: .#+.  :=\n");
    printw("                                 :+ =#*%%+*:%%..+: :=*=-   :=:\n");
    printw("                              .-+#=  .::-====-=--:.:.:++=:\n");
    printw("                          :*#%%#=-== ...-:.     . :+==:\n");
    printw("                           -+#%%@@@++-:...:-==**+@#\n");
    printw("                               :=-   ......  *@.=@%%.\n");
    printw("                                         -**--@: :%%\n");
    printw("                                         :*@#+@.   ##\n");
    printw("                                           .+@@*-  .%%=\n");
    printw("                                             *@+#@#+=@:\n");
    printw("                                             #@. .-+*#+\n");
    printw("                                             %%@.\n");
    printw("                                             %%@\n");
    printw("                             =**+==:.        @@\n");
    printw("                             @@===+*%%#+:    @%%\n");
    printw("                             %%       :*@@+..@*\n");
    printw("                            .@%%          +@@#@-\n");
    printw("                            *@@           .=#@+\n");
    printw("                             +@              #@=\n");
    printw("                                              #@:\n");
    printw("                                               #%%\n");
    printw("                                               .%%+\n");
    printw("                                                :@.\n");
    printw("                                                 ##\n");
    printw("                                                -@*\n");
    printw("                                              .#@=\n");
    printw("                                             :%%.\n");
    printw("                                             @@.\n");
    printw("                                            .@@#+-:\n");
    printw("                                              :----.\n");

    refresh();
    napms(100);
    refresh();
    clear();

    mvprintw(0, 0, " ");
    printw("                                    ...:::-:\n");
    printw("                                .-=+======-=-:....=+:\n");
    printw("                             .==+=:..    :......:.  :=\n");
    printw("                            -+  :...-    :.=+++=.    .*=\n");
    printw("                            #.  :====-.  *==#%%#+=.==-+--+=\n");
    printw("                          -*-.:..:-:-@:  .:  .-=-==+*:==.+\n");
    printw("                          +=:--=-= :#-  .-*= .:=*+.-*.:-=+\n");
    printw("                          :#-.=@=..-=-- -==**---#*+*   =+\n");
    printw("                           .#.*#%%=#::*+=#:.-%%+-:%%+   =-\n");
    printw("                            ---@@@@#%%@@@%%@=:.*-==. .:=\n");
    printw("                            .+ +%%##*=:*..#-----..:++-\n");
    printw("                             +  .----=--:  ..::++-\n");
    printw("                             + ...-::..   ..=++%%@=\n");
    printw("                             ==.     .:=+#=-.   =%%:\n");
    printw("                              -@@*-:-:. =@.       +@*.\n");
    printw("                              #@*.      -@:        .#%%:\n");
    printw("                               :#@*.-+= :@=         :@@.\n");
    printw("                                 :*@@@@..@#      =%%%%=\n");
    printw("                                   .--   @@.     .*-\n");
    printw("                                         #@+\n");
    printw("                                         -@@.\n");
    printw("                                          @@+\n");
    printw("                                          =%%------------:::\n");
    printw("                                          +@@#+===========++++##*=\n");
    printw("                                        +@#-                 :*@#-\n");
    printw("                                      =@#:                .=%%#=.\n");
    printw("                                    -%%#:                :*%%+.\n");
    printw("                                  :#%%-                 -@+\n");
    printw("                                 *@=                   .@#\n");
    printw("                               =@*                      -@.\n");
    printw("                              #@=\n");
    printw("                              .*@*.\n");
    printw("                                :#@*.\n");
    printw("                                  -%%@+\n");
    printw("                                 :+%%%%+\n");
    printw("                                 --.\n");

    refresh();
    napms(100);
    refresh();
    clear();

    mvprintw(0, 0, " ");
    printw("                                 ..\n");
    printw("                                :-======--:-==-\n");
    printw("                          .=+++-::..:::::..   .=\n");
    printw("                        -==-:--.   :  :---:.   .+*-.\n");
    printw("                      .*. ..   .   :+=*@#*=.-=+-=--+:\n");
    printw("                      :+   *#%%%%*. :+=. -+==-**+-*.:*\n");
    printw("                     :*:....:. =+   :=. . :*+ -+.:-+:\n");
    printw("                     *=---===.=%%   ==:+==-:#*+%%.  *=\n");
    printw("                     .*- =@+-..:=*=+---#*#*-#*.  -%%%%%%##*-\n");
    printw("                       *.=@#+#=:**+#**+=*:.=-   =:  -=+%%=\n");
    printw("                        + %%@@@@@%%@+=== .-*-..:=+.  .%%*-\n");
    printw("                        + .*@#*#++*--+-:.::==-\n");
    printw("                        -=   ::...    . :+%%.\n");
    printw("                        .* ....... .:==+@@#.\n");
    printw("                         -*-.  .-++*@#%%@+.\n");
    printw("                           :--:#@=*%%@%%-.\n");
    printw("                               +#*-:@@\n");
    printw("                                    #@:\n");
    printw("                                    :@+\n");
    printw("                                     #@\n");
    printw("                                     :@+                 .:-:\n");
    printw("                                      #@.       .:-=+*###*%%@-\n");
    printw("                                      :@*:=+*###*+-:.    +@-\n");
    printw("                                       =@%%+-:           +@-\n");
    printw("                                      +@-              +@-\n");
    printw("                                    +@*               #@-\n");
    printw("                                  -%%*.               :#@+:\n");
    printw("                                .#%%:                   .=%%:\n");
    printw("                               =@+                        .\n");
    printw("                             .#%%-\n");
    printw("                             *@=\n");
    printw("                              =%%@+\n");
    printw("                               .*@@=\n");
    printw("                                 :%%@#:\n");
    printw("                               .=#%%*-.\n");
    printw("                               ==.\n");

    refresh();
    napms(100);
    refresh();
    clear();

    mvprintw(0, 0, " ");

    printw("                          .:------==:\n");
    printw("                         .-++====--:::.   :=:\n");
    printw("                      -=+=-.    :  ......   .+=.\n");
    printw("                    -=.:-:...   .-=*@@@*..-==+-=+.\n");
    printw("                   .=  ..-=-=:  =*-=-==-=-+*-:#- =\n");
    printw("                   +-.  -==-=*   ..    .++.-+.--+-\n");
    printw("                  #=:===== :#-  =+==:-=-**+%%.  ==\n");
    printw("                  +#-.:%%. .=++=..-=*%%-+%%*#*.   +\n");
    printw("                   -*.-@#+=-:-+-*=:=#%%= .*:  :+    .-*#=\n");
    printw("                    :*.@%%##*+#@@%%#*. .*=- .-+= .-*#+-@%%\n");
    printw("                     +::%%@%%##+-+.:%%---..:-+==*#+-.  +@.\n");
    printw("                     .+ .==+=+==-. ...:+##*+-     -@@-\n");
    printw("                      +  .::::..   :=*@*-.         :\n");
    printw("                      -= ...  .-===-%%@%% .\n");
    printw("                       .==--:-:.   #%%@@%%@#\n");
    printw("                                  *#.@@@%%.\n");
    printw("                                 .@- @@@:\n");
    printw("                                 .@-=@@+\n");
    printw("                                  =###@+\n");
    printw("                                     =@*\n");
    printw("                                     :@%%\n");
    printw("                                     :@@.\n");
    printw("                                     .@@-\n");
    printw("                                      @@+\n");
    printw("                                      #@%%           .-=+*##.\n");
    printw("                                      :@@.    .-+*#*+=-:..@=\n");
    printw("                                       :%%*****+=:         @.\n");
    printw("                                      .*%%=               =%%\n");
    printw("                                     -%%*.                @*\n");
    printw("                                   :#%%:                 -@+\n");
    printw("                                 .*#:                    =*%%#=\n");
    printw("                                =%%=                         ..\n");
    printw("                              .#*.\n");
    printw("                              #%%\n");
    printw("                               #%%:\n");
    printw("                                #@-\n");
    printw("                                 =@*\n");
    printw("                                  +@%%:\n");
    printw("                              .+#*+=.\n");

    refresh();
    napms(100);
    refresh();
    clear();

    mvprintw(0, 0, " ");
    printw("                                 .::--:\n");
    printw("                              .:========-:.  :==:\n");
    printw("                          .=++=-.   .....:...   --\n");
    printw("                        :+-.--::.   : :=+**=..  .-*+-\n");
    printw("                        +  . .::-.  :#==##+-:-=*-=+::=\n");
    printw("                       ==.. =****%%.  :.   -=::++%%+==:+\n");
    printw("                      ==:=---=. =+   .==..:=#=.=+ .-*:\n");
    printw("                      -#:..*.. =#-:.===**=--##=*   =:\n");
    printw("                       =* =@#+=-.=*=#+..*%%*=.%%*.  =:   .:-\n");
    printw("                        -=-@###+=#%%#@@#=:-==+:  .+-=*%%%%@@:\n");
    printw("                         %% *%%@@#%%+*=. +:---:..=#@@%%*+--#@:\n");
    printw("                         +: -+=**+-+--:...:-*%%*+:.   +@@-\n");
    printw("                         .= ..::...    .:+%%        %%@@#\n");
    printw("                          *. ..... :===+@%%#        .-:\n");
    printw("                           +++=--==-  .@%%-%%*\n");
    printw("                                     -%%*@@@+\n");
    printw("                                    *@@#++@+\n");
    printw("                                   +@#:  :@-\n");
    printw("                                   -:    -@-\n");
    printw("                                         -@:\n");
    printw("                                         :@.\n");
    printw("                                         .@:\n");
    printw("                                          @:\n");
    printw("                                          %%-\n");
    printw("                                          *#:.\n");
    printw("                                        =%%@+=+**+:\n");
    printw("                                      :%%@+      .-**+:\n");
    printw("                                    .+@*.           :+%%#=.\n");
    printw("                                   -@#:                .%%@:\n");
    printw("                                  =#:                  +@=\n");
    printw("                                 *+                   +@*\n");
    printw("                                :@:                  =@#\n");
    printw("                                 @*                  @#\n");
    printw("                                 *@.                :*#%%@+\n");
    printw("                                 :@+                    :-\n");
    printw("                                  *%%\n");
    printw("                                 .=@-\n");
    printw("                               =##=.\n");

    refresh();
    napms(100);
    refresh();
    clear();

    const char *art = 
        "                                      :-====+====-----::\n"
        "                                  :=----:..  ..:...:.. .=+\n"
        "                                 :*  .: ..:    -....:..  .* \n"
        "                                =+:  .+++=:   .==+**+:.   .= \n"
        "                               +=:=--..::=%%-  =+-=*#== :----*= \n"
        "                               ++: =:-- -*:   :-   :--=+*-:*:-+ \n"
        "                                %%.-@#=..==-.:+-+.:-==*-.-*-#-.= \n"
        "                                +:*%%-*:.+==+--=%%=--*#=%%=  .*= \n"
        "                                *.=@@@@%%@%#%*++##-::#+.  .+: \n"
        "                                %%  *##+%%-*-.=:  .#==-   .=: \n"
        "                               .#  .:::-==-:-----:...=+=- \n"
        "                               :# .:.:-...   ....=*%%+. \n"
        "                                -+-.    .:--===*@=.+@+ \n"
        "                                  :#*-:--..    =@=  :#%%= \n"
        "                                  =%%*:         -@=    =@#. \n"
        "                                    =%%*:       -@-      *@- \n"
        "                                      -%%@@:    +@-*%%*+===%%@= \n"
        "                                        :*=    *@:.-======: \n"
        "                                               %% \n"
        "                                              +@: \n"
        "                                             :@+ \n"
        "                                   .:-=+++**+%% \n"
        "                               -*%%#*+=--::..%%@+ \n"
        "                              *%%:             =@+ \n"
        "                              =@.              =@- \n"
        "                               #%%               +@. \n"
        "                               -@=               %%* \n"
        "                                @%%              .@- \n"
        "                               -%%@.             #@ \n"
        "                             .@@@#             .@* \n"
        "                                               -@= \n"
        "                                               +@. \n"
        "                                               -%%*-. \n"
        "                                                 -#@* \n"
        "                                                   .. \n";

    mvprintw( 0,0,"%s", art);
    refresh();
}
    attroff(A_BOLD);
    attroff(COLOR_PAIR(6));
    */
   //printTrolls();
   //trollFace();
    mainMenu();
    return 0;
}

