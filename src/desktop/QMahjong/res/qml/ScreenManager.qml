import QtQuick 2.4
import QtQml.StateMachine 1.0 as FSM

Item {
    id: screenManager
    property FSMEvent fsmEvent: FSMEvent {}

    Loader{
        id: mainLoader
        anchors.fill: parent
    }

    FSM.StateMachine {
        id: stateMachine
        initialState: mainMenu
        running: true

        FSM.State {
            id: mainMenu
            onEntered: mainLoader.source = "menu/MainMenu.qml"

            FSM.SignalTransition {
                targetState: interactiveTable
                signal: fsmEvent.openIT
            }

            FSM.SignalTransition {
                targetState: cabinet
                signal: fsmEvent.openCabinet
            }

            FSM.SignalTransition {
                targetState: news
                signal: fsmEvent.openNews
            }

            FSM.SignalTransition {
                targetState: rules
                signal: fsmEvent.openRules
            }
        }

        FSM.State {
            id: interactiveTable
            onEntered: mainLoader.source = "itable/ITView.qml"
        }

        FSM.State {
            id: cabinet
            //onEntered: mainLoader.source = ".qml"
        }

        FSM.State {
            id: news
            //onEntered: mainLoader.source = ".qml"
        }

        FSM.State {
            id: rules
            //onEntered: mainLoader.source = ".qml"
        }
    }
}
