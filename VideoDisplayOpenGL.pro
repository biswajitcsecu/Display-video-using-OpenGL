QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

##########***********Include Directory***********########
INCLUDEPATH += /opt/boost/include
INCLUDEPATH += /opt/opencv/include/opencv4
INCLUDEPATH += /opt/opencv/include
INCLUDEPATH += /opt/openmp/include
INCLUDEPATH += /opt/openmpi/include
INCLUDEPATH += /opt/freeglut/include
INCLUDEPATH += /opt/opencv/include
###############*************Library**************#########
LIBS += -L/opt/opencv/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -lopencv_ml
LIBS += -L/opt/opencv/lib -lopencv_face -lopencv_flann -lopencv_fuzzy -lopencv_shape -lopencv_xphoto
LIBS += -L/opt/opencv/lib -lopencv_stereo -lopencv_calib3d -lopencv_xobjdetect -lopencv_xfeatures2d
LIBS += -L/opt/opencv/lib -lopencv_optflow -lopencv_saliency -lopencv_imgcodecs -lopencv_features2d
LIBS += -L/opt/opencv/lib -lopencv_ximgproc -lopencv_tracking -lopencv_video -lopencv_videoio -lomp
LIBS += -L/opt/opencv/lib -lboost_wave -lboost_fiber -lboost_graph -lboost_regex -lboost_timer -lopencv_stitching
LIBS += -L/opt/opencv/lib -lboost_atomic -lboost_chrono -lboost_locale -lboost_random -lboost_system
LIBS += -L/opt/opencv/lib -lboost_thread -lboost_context -lboost_container -lboost_coroutine
LIBS += -L/opt/opencv/lib -lboost_date_time -lboost_iostreams  -lboost_type_erasure -lopencv_tracking
LIBS += -L/opt/opencv/lib -lboost_serialization -lboost_wserialization -lboost_math_c99 -lgomp
LIBS += -L/opt/opencv/lib -lboost_stacktrace_basic -lboost_math_c99l -lboost_program_options -lomp
LIBS += -L/opt/opencv/lib -lboost_contract -lboost_log_setup -lboost_program_options -lboost_thread
LIBS += -L/opt/opencv/lib -lopencv_xphoto -lopencv_xobjdetect -lopencv_ximgproc -lopencv_videostab
LIBS += -L/opt/opencv/lib -lopencv_text -lopencv_surface_matching -lopencv_superres -lopencv_structured_light
LIBS += -L/opt/opencv/lib -lopencv_stitching -lopencv_shape -lopencv_sfm -lopencv_rgbd -lopencv_reg
LIBS += -L/opt/opencv/lib -lopencv_plot -lopencv_objdetect -lopencv_ml -lopencv_imgcodecs -lboost_math_tr1
LIBS += -L/opt/opencv/lib -lvisp_mbt -lvisp_io -lvisp_ar -lvisp_blob -lvisp_detection -lvisp_gui
LIBS += -L/opt/opencv/lib -lvisp_klt -lvisp_me -lvisp_robot -lvisp_sensor -lvisp_tt -lvisp_tt_mi -lassimp
LIBS += -L/opt/opencv/lib -lvisp_visual_features -lvisp_vs -lvisp_imgproc -lvisp_vision -lvisp_core -larmadillo
LIBS += -L/opt/openmpi/lib -lmpi -lopen-pal  -lmpi_mpifh -lopen-rte -lmca_common_verbs -lompitrace
LIBS += -L/opt/openmpi/lib -lmca_common_sm -lmpi_usempif08 -lmpi_usempi_ignore_tkr -larmadillo -lvisp_me
LIBS += -L/opt/openmpi/lib -lmca_common_dstore -lmca_common_monitoring -lmca_common_ompio  -lOpenImageDenoise
LIBS += -L/opt/freeglut/lib -lGL -lGLEW -lglfw -lGLU -lglut -lGLX -lvisp_visual_features -lvisp_robot
LIBS += -L/opt/opencv/lib  -lGL -lGLEW -lglfw -lGLU -lglut -lGLX -lglm_shared -lvisp_core -lvisp_blob -liomp5
####################**********END*********************##################################








# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
