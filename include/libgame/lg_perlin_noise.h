/*
 *	LibGame - Copyright (C) Emmanuel Thomas-Maurin 2011-2024
 *	All rights reserved
 */

#ifndef LG_PERLIN_NOISE_H
#define LG_PERLIN_NOISE_H

// === NOTE: FOLLOWING CODE IS COPYRIGHT(C) 2023 JORDAN PECK ===

/*
 * Fast Noise Lite
 * Copyright(c) 2023 Jordan Peck (jordan.me2@gmail.com)
 * Copyright(c) 2023 Contributors
 * MIT License
 */

// Switch between using floats or doubles for input position
typedef float FNLfloat;
//typedef double FNLfloat;

// Enums
typedef enum
{
	FNL_NOISE_OPENSIMPLEX2,
	FNL_NOISE_OPENSIMPLEX2S,
	FNL_NOISE_CELLULAR,
	FNL_NOISE_PERLIN,
	FNL_NOISE_VALUE_CUBIC,
	FNL_NOISE_VALUE
} fnl_noise_type;

typedef enum
{
	FNL_ROTATION_NONE,
	FNL_ROTATION_IMPROVE_XY_PLANES,
	FNL_ROTATION_IMPROVE_XZ_PLANES
} fnl_rotation_type_3d;

typedef enum
{
	FNL_FRACTAL_NONE,
	FNL_FRACTAL_FBM,
	FNL_FRACTAL_RIDGED,
	FNL_FRACTAL_PINGPONG,
	FNL_FRACTAL_DOMAIN_WARP_PROGRESSIVE,
	FNL_FRACTAL_DOMAIN_WARP_INDEPENDENT
} fnl_fractal_type;

typedef enum
{
	FNL_CELLULAR_DISTANCE_EUCLIDEAN,
	FNL_CELLULAR_DISTANCE_EUCLIDEANSQ,
	FNL_CELLULAR_DISTANCE_MANHATTAN,
	FNL_CELLULAR_DISTANCE_HYBRID
} fnl_cellular_distance_func;

typedef enum
{
	FNL_CELLULAR_RETURN_TYPE_CELLVALUE,
	FNL_CELLULAR_RETURN_TYPE_DISTANCE,
	FNL_CELLULAR_RETURN_TYPE_DISTANCE2,
	FNL_CELLULAR_RETURN_TYPE_DISTANCE2ADD,
	FNL_CELLULAR_RETURN_TYPE_DISTANCE2SUB,
	FNL_CELLULAR_RETURN_TYPE_DISTANCE2MUL,
	FNL_CELLULAR_RETURN_TYPE_DISTANCE2DIV,
} fnl_cellular_return_type;

typedef enum
{
	FNL_DOMAIN_WARP_OPENSIMPLEX2,
	FNL_DOMAIN_WARP_OPENSIMPLEX2_REDUCED,
	FNL_DOMAIN_WARP_BASICGRID
} fnl_domain_warp_type;

/**
 * Structure containing entire noise system state.
 * @note Must only be created using fnlCreateState(optional: seed). To ensure defaults are set.
 */
typedef struct fnl_state
{
	/**
	 * Seed used for all noise types.
	 * @remark Default: 1337
	 */
	int seed;

	/**
	 * The frequency for all noise types.
	 * @remark Default: 0.01
	 */
	float frequency;

	/**
	 * The noise algorithm to be used by GetNoise(...).
	 * @remark Default: FNL_NOISE_OPENSIMPLEX2
	 */
	fnl_noise_type noise_type;

	/**
	 * Sets noise rotation type for 3D.
	 * @remark Default: FNL_ROTATION_NONE
	 */
	fnl_rotation_type_3d rotation_type_3d;

	/**
	 * The method used for combining octaves for all fractal noise types.
	 * @remark Default: None
	 * @remark FNL_FRACTAL_DOMAIN_WARP_... only effects fnlDomainWarp...
	 */
	fnl_fractal_type fractal_type;

	/**
	 * The octave count for all fractal noise types.
	 * @remark Default: 3
	 */
	int octaves;

	/**
	 * The octave lacunarity for all fractal noise types.
	 * @remark Default: 2.0
	 */
	float lacunarity;

	/**
	 * The octave gain for all fractal noise types.
	 * @remark Default: 0.5
	 */
	float gain;

	/**
	 * The octave weighting for all none Domaain Warp fractal types.
	 * @remark Default: 0.0
	 * @remark
	 */
	float weighted_strength;

	/**
	 * The strength of the fractal ping pong effect.
	 * @remark Default: 2.0
	 */
	float ping_pong_strength;

	/**
	 * The distance function used in cellular noise calculations.
	 * @remark Default: FNL_CELLULAR_DISTANCE_EUCLIDEANSQ
	 */
	fnl_cellular_distance_func cellular_distance_func;

	/**
	 * The cellular return type from cellular noise calculations.
	 * @remark Default: FNL_CELLULAR_RETURN_TYPE_DISTANCE
	 */
	fnl_cellular_return_type cellular_return_type;

	/**
	 * The maximum distance a cellular point can move from it's grid position.
	 * @remark Default: 1.0
	 * @note Setting this higher than 1 will cause artifacts.
	 */
	float cellular_jitter_mod;

	/**
	 * The warp algorithm when using fnlDomainWarp...
	 * @remark Default: OpenSimplex2
	 */
	fnl_domain_warp_type domain_warp_type;

	/**
	 * The maximum warp distance from original position when using fnlDomainWarp...
	 * @remark Default: 1.0
	 */
	float domain_warp_amp;
} fnl_state;

fnl_state	fnlCreateState();

float		fnlGetNoise2D(fnl_state *, FNLfloat, FNLfloat);

float		fnlGetNoise3D(fnl_state *, FNLfloat, FNLfloat, FNLfloat);

void		fnlDomainWarp2D(fnl_state *, FNLfloat *, FNLfloat *);

void		fnlDomainWarp3D(fnl_state *, FNLfloat *, FNLfloat *, FNLfloat *);

#endif /* LG_PERLIN_NOISE_H */