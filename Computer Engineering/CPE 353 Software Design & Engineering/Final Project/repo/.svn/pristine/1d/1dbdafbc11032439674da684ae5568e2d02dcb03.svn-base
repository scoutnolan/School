#ifndef MESSAGE_H
#define MESSAGE_H

enum class Message{
    // Client speaking to the server.
    StartGame,              // This is for if the host starts the game.
    Moved,                  // client moved
    Dodge,                  // Updates client dodging.
    Tag,                    // When the client presses the p button to tag.
    Die,                    // When the client gets tagged.
    Respawn,                // When the client respawns.
    ExitGame,               // This is for when a client leaves the game.
    PlayerTag,              // Emits the number of tags the User has.

    // Server Speaking to Client
    Error,                  // Error messages.
    PlayerColor,            // Server telling the clients the different Player's colors.
    UpdatePlayerPos,        // Update the player's coords (using their ID).
    TagPressed,             // Update the board with another players tag.
    UpdateLeaderboard,      // Update Leaderboard
    SendToLeaderboard,      // Send the scores to the Database
    LoadGame,               // Load the game and create the player objects maybe
    UpdatePlayerName,       // Update the list of player names
    SetId,                  // Client ID
    RemoveObject,           // Need to remove any object, could be the tag or the player respawning.
    AddObject,              // Add back an object.
    GameStart,              // Start the game with all of the other users data?

    //Lobby Chat
    Message,                // Send Message to player in lobby chat
};

enum class Color
{
    White,
    Red,
    Green,
    Blue,
    Gray,
    Cyan,
    Pink,
    Yellow,
};

#endif // MESSAGE_H
