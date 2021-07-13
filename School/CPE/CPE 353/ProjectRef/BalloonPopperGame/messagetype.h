#ifndef MESSAGETYPE_H
#define MESSAGETYPE_H

//this enum holds all the msg types for the server
//any file which needs to encode/decode a message just needs to include this file, and use STRICT CASTING (such as "int x = static_cast<int>(MessageType::Error)"), WELL-DEFINED SCOPE (eg. MessageType::HSRequest)
//Convert the type to an int, insert into a textstream, followed by whitespace, followed by the data section of the message.
//separate elements of a msg are separated by white space, sent via a QTextStream

//should it be an enum class? i think so? ;]
enum class MessageType {
    //-------- Client->Server Messages
    ColorChangeRequest,     //tells the server:  "hey, i want this color. it's mine" if the color is not already taken, the server should send all players a notice that that color is claimed.
    StartGameRequest,       //player1 should be the only one to press this. Upon receival, server initializes game
    MovedLeft,              //these two msgs tell the server to update the other client's coords w/ new ones. (could also have server take movingleft input and stopmovingleft input, and calculate new coords itself)
    MovedRight,
    ShootPellet,            //tell server to create pellet obj on sender's current coords. Server sends this info to all clients (including the client who fired the pellet?)
    ExitGame,               //at the end of the game, player clicks exit to leave the lobby
    PlayAgain,              //tell server that player would like to leave the  game, but stay in the lobby.
    IncPlayerScore,         //tell server to increase a player's score

    //-------- Server->Client Messages
    Error,                  //string containing error msg
    ColorChanged,           //player id, color type (colors enummed?)
    GameStart,              //some sort of variable-length list. Perhaps:  numPlayers, player1 id, player1 name, player1 position, player1 color, player2 ..., player_n color (sent opon receiving startgamerequest)
    TimerSync,              //some sort of output from QTimer (each player will set their timers to this. COULD be a part of GameStart, not sure;   though it may be necessary every minute or so)
    PlayerPosChange,        //player id, new coords
    //BalloonAdded,           //server creates a balloon at a random location at certain time intervals. sends [balloonID, coords] to each client. Alternatively, send each player a seed at gamestart. Then, each player makes own balloons at set times. If the seeds match, the balloon spawns should match.
    PelletAdded,            //similar idea to balloonadded. upon receiving shootpellet, server creates pellet at player's coords, sends [pelletID, coords] to each client.
    EntityRemoved,          //unique entityID. if there is no overlap between entities of different types, we won't need to differentiate between different types in this msg. ie. send msg saying entity [57] has been removed. Then, each player removed entity [57], which could be a balloon or a pellet.
    UpdatePlayerScores,     //variable list: [numplayers, player1name, player2score, player3name, ..., player_n_scores]
    SendFinalScores,        //sends the final scores to gameenddialog
    LoadGame,               //signal players to create game object
    UpdatePlayerName,       //tell client to update name and id list
    SetId,                  //tell client their id
    BalloonSchedule,        //Server creates balloon spawn schedule and sends it to all clients for them to use to create balloons for the game
};

enum class Color{
    Red,
    Pink,
    Cyan,
    Yellow,
    Green,
    Blue,
    Purple,
    Black,
    NullColor,
};

#endif //MESSAGETYPE_H
