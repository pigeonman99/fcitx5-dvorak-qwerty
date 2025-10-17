# Make sure it produce dq.so instead of libdq.so
add_library(dq SHARED dq.cpp)
target_link_libraries(dq PRIVATE Fcitx5::Core)
set_target_properties(dq PROPERTIES PREFIX "")
install(TARGETS dq DESTINATION "${FCITX_INSTALL_LIBDIR}/fcitx5")

# Addon config file
# We need additional layer of conversion because we want PROJECT_VERSION in it.
configure_file(dq-addon.conf.in dq-addon.conf)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/dq-addon.conf" RENAME dq.conf DESTINATION "${FCITX_INSTALL_PKGDATADIR}/addon")

# Input Method registration file
install(FILES "dq.conf" DESTINATION "${FCITX_INSTALL_PKGDATADIR}/inputmethod")