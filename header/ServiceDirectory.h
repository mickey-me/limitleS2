#ifndef ServiceDirectory_H
#define ServiceDirectory_H

#include <map>
#include <vector>

#include "../header/Server.h"
#include "../header/Message.h"
#include "../common/DataStructures.cpp"

class ServiceDirectory : public Server
{
    private:
      std::map<string, UserInfo> Users;
    public:
        ServiceDirectory(int _listen_port);

        Message * doOperation(Message * message);

        //getters
        bool IsUser(string name);
        //bool IsAuthorized(string name);

        bool SignUp(UserInfo userInfo);
        bool SignIn(AuthInfo authInfo);
        bool SignOut(AuthInfo authInfo);

        bool UpdateConnectionInfo(UserInfo userInfo);

        vector<UserInfo> GetOnlineUsers();

        ~ServiceDirectory();
};

#include "../source/ServiceDirectory.cpp"
#endif // ServiceDirectory_H
