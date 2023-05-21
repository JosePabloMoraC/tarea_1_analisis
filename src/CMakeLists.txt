set(HEADER_LIST "${TareaProgramada1_SOURCE_DIR}/include/*.hh")

add_executable(TareaProgramada1 main.cc arbolHMI_HD.cc traductor.cc colaLSE.cc)
target_include_directories(
	TareaProgramada1
	PUBLIC
	"${TareaProgramada1_SOURCE_DIR}/include")