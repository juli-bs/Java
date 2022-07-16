# TODO Aufgabe 1:
#  Definiert eine Anwendung `smallpt`, die mindestens `main.cpp` kompiliert.
#
# ???
#

add_executable(smallpt
        app/main.cpp
        app/app.cpp app/app.h
        libObjects/Vec.h
        libObjects/Ray.h
        libObjects/Sphere.h
        app/Constants.h)


# Unter Linux wird für Threads eine extra Bibliothek benötigt. Das haben wir für die Anwendung `smallpt` schon mal vorbereitet.
if(UNIX)
    target_link_libraries(smallpt pthread)
endif()
