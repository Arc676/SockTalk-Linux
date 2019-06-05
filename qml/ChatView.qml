// Copyright (C) 2019 Arc676/Alessandro Vinciguerra <alesvinciguerra@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation (version 3)

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

import QtQuick 2.4
import QtQuick.Layouts 1.1
import Ubuntu.Components 1.3

import SockTalkFrontend 1.0

Page {
	id: chatPage
	anchors.fill: parent
	header: DefaultHeader {}

	Column {
		id: connectionCol
		spacing: margin
		width: parent.width - 2 * margin
		anchors {
			top: header.bottom
			topMargin: margin
			horizontalCenter: parent.horizontalCenter
		}

		Row {
			width: parent.width
			spacing: margin

			Label {
				id: hostLbl
				text: i18n.tr("Host:")
				anchors.verticalCenter: hostField.verticalCenter
			}

			TextField {
				id: hostField
				width: parent.width - hostLbl.width - margin
			}
		}

		Row {
			width: parent.width
			spacing: margin

			Label {
				id: postLbl
				text: i18n.tr("Port:")
				anchors.verticalCenter: portField.verticalCenter
			}

			TextField {
				id: portField
				width: parent.width - postLbl.width - margin
			}
		}

		Row {
			width: parent.width
			spacing: margin

			Label {
				id: usernameLbl
				text: i18n.tr("Nickname:")
				anchors.verticalCenter: usernameField.verticalCenter
			}

			TextField {
				id: usernameField
				width: parent.width - usernameLbl.width - margin
			}
		}

		Row {
			width: parent.width
			spacing: margin

			Button {
				id: connectButton
				width: (parent.width - margin) / 2
				text: i18n.tr("Connect")
				onClicked: {
					var port = parseInt(portField.text)
					if (SockTalkFrontend.connect(hostField.text, port, usernameField.text, "", "")) {
						disconnectButton.enabled = true
						connectButton.enabled = false
					}
				}
			}

			Button {
				id: disconnectButton
				width: (parent.width - margin) / 2
				text: i18n.tr("Disconnect")
				enabled: false
				onClicked: {
					if (SockTalkFrontend.disconnect()) {
						connectButton.enabled = true
						disconnectButton.enabled = false
					}
				}
			}
		}
	}

	Flickable {
		id: flickable
		width: parent.width - 2 * margin
		anchors {
			top: connectionCol.bottom
			topMargin: margin
			bottom: msgRow.top
			bottomMargin: margin
			horizontalCenter: parent.horizontalCenter
		}

		TextArea {
			id: transcript
			anchors.fill: parent
		}
	}

	Row {
		id: msgRow
		spacing: margin
		width: parent.width - 2 * margin
		anchors {
			bottom: parent.bottom
			bottomMargin: margin
			horizontalCenter: parent.horizontalCenter
		}

		TextField {
			id: msgField
			width: parent.width - sendBtn.width - margin
			placeholderText: "Message"
		}

		Button {
			id: sendBtn
			text: i18n.tr("Send")
			onClicked: {
				if (SockTalkFrontend.sendMessage(msgField.text)) {
					msgField.text = ""
				}
			}
		}
	}
}
