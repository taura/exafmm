ADD_EXECUTABLE(serialrun serialrun.cxx)
TARGET_LINK_LIBRARIES(serialrun Kernels)
ADD_TEST(serialrun ${CMAKE_CURRENT_BINARY_DIR}/serialrun)

IF(USE_MPI)
  ADD_EXECUTABLE(parallelrun parallelrun.cxx)
  TARGET_LINK_LIBRARIES(parallelrun Kernels)
  ADD_TEST(parallelrun ${MPIEXEC} -np 2 ${CMAKE_CURRENT_BINARY_DIR}/parallelrun)
ENDIF()
