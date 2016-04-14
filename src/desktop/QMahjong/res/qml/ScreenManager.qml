import QtQuick 2.0

Item {
    id: screenManager

    Loader{
        id: mainLoader
        anchors.fill: parent
    }

    states:[
        State {
            // Cabinet "Sign In"
            name: "SIGNIN"
            PropertyChanges {target:mainLoader; source: "cabinet/SignInForm.qml";}
        }
    ]
}

