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

Page {
	id: chatPage
	header: DefaultHeader {}

	Column {
		spacing: margin
		width: parent.width - 2 * margin
		anchors {
			top: header.bottom
			topMargin: margin
			bottom: flickable.top
			bottomMargin: margin
			horizontalCenter: parent.horizontalCenter
		}

		Row {
			Label {
				text: i18n.tr("Host:")
			}

			TextField {
				id: hostField
			}
		}

		Row {
			Label {
				text: i18n.tr("Port:")
			}

			TextField {
				id: portField
			}
		}

		Row {
			Label {
				text: i18n.tr("Nickname:")
			}

			TextField {
				id: usernameField
			}
		}
	}

	Flickable {
		id: flickable
		width: parent.width - 2 * margin
		anchors {
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
		spacing: margin
		width: parent.width - 2 * margin
		anchors {
			bottom: parent.bottom
			bottomMargin: margin
			horizontalCenter: parent.horizontalCenter
		}

		TextField {
			id: msgField
			placeholderText: "Message"
		}

		Button {
			onClicked:
		}
	}
}
