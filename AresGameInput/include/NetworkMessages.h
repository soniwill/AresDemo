#ifndef NETWORKMESSAGES_H
#define NETWORKMESSAGES_H
#include <string.h>

using namespace std;

class NetworkMessages
{
    public:

        virtual ~NetworkMessages();

        //  NETWORK MESSAGES THAT WILL BE SENT TO THE UNITY CLIENT

        /** \brief This message should be used to send data from the server to the client about the player movement
         *
         * \param forward: float
         * \param  right: float
         * \param  left: float
         * \param  backward: float
         *  example: MOVEMENT_PLAYER;75.0;50.0;50.0;35.0
         */
        static string MOVEMENT_PLAYER; //= "MOVEMENT_PLAYER";


        /** \brief This message should be used to send data from the server to the client about the weapon rotation
         *
         * \param rotation: float (0.0 to 359.0)
         *  example: WEAPON_ROTATION;270.0;
         */
        static string WEAPON_ROTATION;// = "WEAPON_ROTATION";


        /** \brief This message should be used to send data from the server to the client about the weapon elevation
         *
         * \param rotation: float (-10.0 to 60.0)
         *  example: WEAPON_ELEVATION;15.5;
         */
        static string WEAPON_ELEVATION;// = "WEAPON_ELEVATION";


        /** \brief This message should be used to send data from the server to the client about the fire weapon action
         *
         *
         *  example: FIRE_WEAPON;
         */


        static string FIRE_WEAPON;// = "FIRE_WEAPON";

         /** \brief This message should be used to inform the server when the client is ready to start the demo.
         *
         *
         *  example: CLIENT_READY;
         */


        static string CLIENT_READY;

         /** \brief This message should be used to order the client start the demo.
         *
         *
         *  example: CLIENT_READY;
         */


        static string START_DEMO;


    protected:

    private:
         NetworkMessages();
};

#endif // NETWORKMESSAGES_H
