include ../Makefile.am.include

bin_PROGRAMS = laplace_cartesian laplace_spherical helmholtz_spherical biotsavart_spherical tree
laplace_cartesian_SOURCES = fmm.cxx ../kernels/LaplaceCartesianCPU.cxx ../kernels/LaplaceP2PCPU.cxx
if EXAFMM_HAVE_FX
laplace_cartesian_CPPFLAGS = $(AM_CPPFLAGS) -DEXAFMM_LAPLACE -DEXAFMM_CARTESIAN -DEXAFMM_MASS -DEXAFMM_EXPANSION=7
else
laplace_cartesian_CPPFLAGS = $(AM_CPPFLAGS) -DEXAFMM_LAPLACE -DEXAFMM_CARTESIAN -DEXAFMM_MASS -DEXAFMM_EXPANSION=10
endif
laplace_spherical_SOURCES = fmm.cxx ../kernels/LaplaceSphericalCPU.cxx ../kernels/LaplaceP2PCPU.cxx
laplace_spherical_CPPFLAGS = $(AM_CPPFLAGS) -DEXAFMM_LAPLACE -DEXAFMM_SPHERICAL -DEXAFMM_EXPANSION=10
helmholtz_spherical_SOURCES = fmm.cxx ../kernels/HelmholtzSphericalCPU.cxx ../kernels/HelmholtzP2PCPU.cxx
helmholtz_spherical_CPPFLAGS = $(AM_CPPFLAGS) -DEXAFMM_HELMHOLTZ -DEXAFMM_SPHERICAL -DEXAFMM_EXPANSION=15
biotsavart_spherical_SOURCES = fmm.cxx ../kernels/BiotSavartSphericalCPU.cxx ../kernels/BiotSavartP2PCPU.cxx
biotsavart_spherical_CPPFLAGS = $(AM_CPPFLAGS) -DEXAFMM_BIOTSAVART -DEXAFMM_SPHERICAL -DEXAFMM_EXPANSION=10
tree_SOURCES = tree.cxx
tree_CPPFLAGS = $(laplace_cartesian_CPPFLAGS)

run_laplace_cartesian: laplace_cartesian
	./$< -Dgmovx -r 10
run_laplace_spherical: laplace_spherical
	./$< -Dgmovx -r 10
run_helmholtz_spherical: helmholtz_spherical
	./$< -Dgv -n 40000 -r 10
run_biotsavart_spherical: biotsavart_spherical
	./$< -Dgv -n 40000 -r 10
run_tree: tree
	./$< -v -n 10000000 -r 10

bin_PROGRAMS += laplace_cartesian_kernel laplace_spherical_kernel helmholtz_spherical_kernel biotsavart_spherical_kernel
laplace_cartesian_kernel_SOURCES = kernel.cxx ../kernels/LaplaceCartesianCPU.cxx ../kernels/LaplaceP2PCPU.cxx
laplace_cartesian_kernel_CPPFLAGS = $(laplace_cartesian_CPPFLAGS)
laplace_spherical_kernel_SOURCES = kernel.cxx ../kernels/LaplaceSphericalCPU.cxx ../kernels/LaplaceP2PCPU.cxx
laplace_spherical_kernel_CPPFLAGS = $(laplace_spherical_CPPFLAGS)
helmholtz_spherical_kernel_SOURCES = kernel.cxx ../kernels/HelmholtzSphericalCPU.cxx ../kernels/HelmholtzP2PCPU.cxx
helmholtz_spherical_kernel_CPPFLAGS = $(helmholtz_spherical_CPPFLAGS)
biotsavart_spherical_kernel_SOURCES = kernel.cxx ../kernels/BiotSavartSphericalCPU.cxx ../kernels/BiotSavartP2PCPU.cxx
biotsavart_spherical_kernel_CPPFLAGS = $(biotsavart_spherical_CPPFLAGS)

run_laplace_cartesian_kernel: laplace_cartesian_kernel
	./$< -v
run_laplace_spherical_kernel: laplace_spherical_kernel
	./$< -v
run_helmholtz_spherical_kernel: helmholtz_spherical_kernel
	./$< -v
run_biotsavart_spherical_kernel: biotsavart_spherical_kernel
	./$< -v

if EXAFMM_HAVE_MPI
bin_PROGRAMS += laplace_cartesian_mpi laplace_spherical_mpi helmholtz_spherical_mpi biotsavart_spherical_mpi ewald_mpi
laplace_cartesian_mpi_SOURCES = fmm_mpi.cxx ../kernels/LaplaceCartesianCPU.cxx ../kernels/LaplaceP2PCPU.cxx
laplace_cartesian_mpi_CPPFLAGS = $(laplace_cartesian_CPPFLAGS)
laplace_spherical_mpi_SOURCES = fmm_mpi.cxx ../kernels/LaplaceSphericalCPU.cxx ../kernels/LaplaceP2PCPU.cxx
laplace_spherical_mpi_CPPFLAGS = $(laplace_spherical_CPPFLAGS)
helmholtz_spherical_mpi_SOURCES = fmm_mpi.cxx ../kernels/HelmholtzSphericalCPU.cxx ../kernels/HelmholtzP2PCPU.cxx
helmholtz_spherical_mpi_CPPFLAGS = $(helmholtz_spherical_CPPFLAGS)
biotsavart_spherical_mpi_SOURCES = fmm_mpi.cxx ../kernels/BiotSavartSphericalCPU.cxx ../kernels/BiotSavartP2PCPU.cxx
biotsavart_spherical_mpi_CPPFLAGS = $(biotsavart_spherical_CPPFLAGS)
ewald_mpi_SOURCES = ewald.cxx ../kernels/LaplaceSphericalCPU.cxx ../kernels/LaplaceP2PCPU.cxx
ewald_mpi_CPPFLAGS = $(laplace_spherical_CPPFLAGS)

run_laplace_cartesian_mpi: laplace_cartesian_mpi
	$(MPIRUN) -n 2 ./$< -Dgmovx -r 10
run_laplace_spherical_mpi: laplace_spherical_mpi
	$(MPIRUN) -n 2 ./$< -Dgmovx -r 10
run_helmholtz_spherical_mpi: helmholtz_spherical_mpi
	$(MPIRUN) -n 2 ./$< -Dgv -n 100000 -r 10
run_biotsavart_spherical_mpi: biotsavart_spherical_mpi
	$(MPIRUN) -n 2 ./$< -Dgv -n 100000 -r 10
run_ewald_mpi: ewald_mpi
	$(MPIRUN) -n 2 ./$< -Dgmovx -r 10
endif
