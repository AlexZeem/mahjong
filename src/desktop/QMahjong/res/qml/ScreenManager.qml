import QtQuick 2.0
import QtQml.StateMachine 1.0 as DSM

Item {
    id: screenManager
    property FSMEvent fsmEvent: FSMEvent {}

    Loader{
        id: mainLoader
        anchors.fill: parent
    }

    DSM.StateMachine {
        id: stateMachine
        initialState: administrationState
        running: true

        DSM.State {
            id: signInState
            onEntered: mainLoader.source = "cabinet/SignInForm.qml"

            DSM.SignalTransition {
                targetState: authFailedState
                signal: auth.validationFailed
            }

            DSM.SignalTransition {
                targetState: cabinetState
                signal: auth.validationSuccesfull
            }

            DSM.SignalTransition {
                targetState: administrationState
                signal: auth.superUserSignIn
            }
        }

        DSM.State {
            id: authFailedState
            onEntered: mainLoader.source = "cabinet/AuthorizationFailedForm.qml"

            DSM.SignalTransition {
                targetState: signInState
                signal: fsmEvent.back
            }
        }

        DSM.State {
            id: cabinetState
            onEntered: mainLoader.source = "cabinet/CabinetForm.qml"

            DSM.SignalTransition {
                targetState: signInState
                signal: fsmEvent.signOut
            }

            DSM.SignalTransition {
                targetState: gameStatState
                signal: fsmEvent.gameStat
            }
        }

        DSM.State {
            id: gameStatState
            onEntered: mainLoader.source = "cabinet/GameStatsForm.qml"

            DSM.SignalTransition {
                targetState: cabinetState
                signal: fsmEvent.back
            }
            DSM.SignalTransition {
                targetState: gameDetailsState
                signal: fsmEvent.gameDetails
            }
        }

        DSM.State {
            id: gameDetailsState
            onEntered: mainLoader.source = "cabinet/GameDetailsForm.qml"

            DSM.SignalTransition {
                targetState: gameStatState
                signal: fsmEvent.back
            }
        }

        DSM.State {
            id: administrationState
            onEntered: mainLoader.source = "cabinet/admin/AdministrationForm.qml"

            DSM.SignalTransition {
                targetState: signInState
                signal: fsmEvent.signOut
            }
        }
    }
}
