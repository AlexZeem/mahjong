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
        },
        State {
            // Cabinet "Authorization Failed"
            name: "AFAILED"
            PropertyChanges {target:mainLoader; source: "cabinet/AuthorizationFailedForm.qml";}
        },
        State {
            // Cabinet
            name: "CABINET"
            PropertyChanges {target:mainLoader; source: "cabinet/CabinetForm.qml";}
        }
    ]
}

