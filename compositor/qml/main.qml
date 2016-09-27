/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Wayland module
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtWayland.Compositor 1.0

import com.theqtcompany.customextension 1.0

WaylandCompositor {
    id: comp

    property var lastItem: null

    property int counter : 0

    function sendEvent() {
        if (lastItem != null) {
            console.log("Compositor sending event: " + counter);
            custom.sendEvent(lastItem.shellSurface.surface, 0, "test", counter);
            counter++;
        }
    }

    Screen {
        compositor: comp
    }

    Component {
        id: chromeComponent
        ShellSurfaceItem {
            id: chrome
            onSurfaceDestroyed: {
                if (chrome === lastItem)
                    lastItem = null;
                chrome.destroy()
            }
            onShellSurfaceChanged: {
                console.log("foo" + shellSurface.className)
            }
            Component.onCompleted: {
                console.log(chrome.shellSurface)
                console.log("foo" + shellSurface.className)
            }
            Connections {
                target: chrome.shellSurface
                onClassNameChanged: {
                    console.log("baas")
                }
            }
        }
    }

    extensions: [
        WlShell {
            id: defaultShell

            onShellSurfaceCreated: {
                var item = chromeComponent.createObject(defaultOutput.surfaceArea, { "shellSurface": shellSurface } );
                lastItem = item;
            }

            Component.onCompleted: {
                console.log ("WL shell set up")
            }
        },
        CustomExtension {
            id: custom
            onRequestReceived: {
                console.log("Compositor received a request: \"" + text + "\", " + value)
            }

            Component.onCompleted: {
                console.log("protocol set up")
            }
        }

    ]

}