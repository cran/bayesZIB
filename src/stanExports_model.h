// Generated by rstantools.  Do not edit by hand.

/*
    bayesZIB is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    bayesZIB is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with bayesZIB.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0

#include <stan/model/model_header.hpp>

namespace model_model_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_model");
    reader.add_event(71, 69, "end", "model_model");
    return reader;
}

template <bool propto, typename T1__, typename T2__>
typename boost::math::tools::promote_args<T1__, T2__>::type
zib_lpmf(const int& y,
             const T1__& w,
             const T2__& p,
             const int& N_ones,
             const int& N, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T1__, T2__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

    int current_statement_begin__ = -1;
    try {

        current_statement_begin__ = 3;
        return stan::math::promote_scalar<fun_return_scalar_t__>(((N_ones * stan::math::log((w * p))) + ((N - N_ones) * stan::math::log((1 - (w * p))))));
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}
template <typename T1__, typename T2__>
typename boost::math::tools::promote_args<T1__, T2__>::type
zib_lpmf(const int& y,
             const T1__& w,
             const T2__& p,
             const int& N_ones,
             const int& N, std::ostream* pstream__) {
    return zib_lpmf<false>(y,w,p,N_ones,N, pstream__);
}


struct zib_lpmf_functor__ {
    template <bool propto, typename T1__, typename T2__>
        typename boost::math::tools::promote_args<T1__, T2__>::type
    operator()(const int& y,
             const T1__& w,
             const T2__& p,
             const int& N_ones,
             const int& N, std::ostream* pstream__) const {
        return zib_lpmf(y, w, p, N_ones, N, pstream__);
    }
};

int
num_ones(const std::vector<int>& y, std::ostream* pstream__) {
    typedef double local_scalar_t__;
    typedef int fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 6;
        int suma(0);
        (void) suma;  // dummy to suppress unused var warning
        stan::math::fill(suma, std::numeric_limits<int>::min());
        stan::math::assign(suma,0);


        current_statement_begin__ = 7;
        for (int n = 1; n <= size(y); ++n) {
            current_statement_begin__ = 8;
            stan::math::assign(suma, (suma + logical_eq(get_base1(y, n, "y", 1), 1)));
        }
        current_statement_begin__ = 9;
        return stan::math::promote_scalar<fun_return_scalar_t__>(suma);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}


struct num_ones_functor__ {
            int
    operator()(const std::vector<int>& y, std::ostream* pstream__) const {
        return num_ones(y, pstream__);
    }
};

class model_model
  : public stan::model::model_base_crtp<model_model> {
private:
        int N;
        int M1;
        int M2;
        std::vector<int> y;
        matrix_d X1;
        matrix_d X2;
        std::vector<double> s_theta;
        std::vector<double> s;
        int N_ones;
public:
    model_model(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_model(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_model_namespace::model_model";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            // initialize data block variables from context__
            current_statement_begin__ = 16;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 0);

            current_statement_begin__ = 18;
            context__.validate_dims("data initialization", "M1", "int", context__.to_vec());
            M1 = int(0);
            vals_i__ = context__.vals_i("M1");
            pos__ = 0;
            M1 = vals_i__[pos__++];
            check_greater_or_equal(function__, "M1", M1, 0);

            current_statement_begin__ = 20;
            context__.validate_dims("data initialization", "M2", "int", context__.to_vec());
            M2 = int(0);
            vals_i__ = context__.vals_i("M2");
            pos__ = 0;
            M2 = vals_i__[pos__++];
            check_greater_or_equal(function__, "M2", M2, 0);

            current_statement_begin__ = 22;
            validate_non_negative_index("y", "N", N);
            context__.validate_dims("data initialization", "y", "int", context__.to_vec(N));
            y = std::vector<int>(N, int(0));
            vals_i__ = context__.vals_i("y");
            pos__ = 0;
            size_t y_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < y_k_0_max__; ++k_0__) {
                y[k_0__] = vals_i__[pos__++];
            }
            size_t y_i_0_max__ = N;
            for (size_t i_0__ = 0; i_0__ < y_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "y[i_0__]", y[i_0__], 0);
                check_less_or_equal(function__, "y[i_0__]", y[i_0__], 1);
            }

            current_statement_begin__ = 23;
            validate_non_negative_index("X1", "N", N);
            validate_non_negative_index("X1", "M1", M1);
            context__.validate_dims("data initialization", "X1", "matrix_d", context__.to_vec(N,M1));
            X1 = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(N, M1);
            vals_r__ = context__.vals_r("X1");
            pos__ = 0;
            size_t X1_j_2_max__ = M1;
            size_t X1_j_1_max__ = N;
            for (size_t j_2__ = 0; j_2__ < X1_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < X1_j_1_max__; ++j_1__) {
                    X1(j_1__, j_2__) = vals_r__[pos__++];
                }
            }

            current_statement_begin__ = 24;
            validate_non_negative_index("X2", "N", N);
            validate_non_negative_index("X2", "M2", M2);
            context__.validate_dims("data initialization", "X2", "matrix_d", context__.to_vec(N,M2));
            X2 = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(N, M2);
            vals_r__ = context__.vals_r("X2");
            pos__ = 0;
            size_t X2_j_2_max__ = M2;
            size_t X2_j_1_max__ = N;
            for (size_t j_2__ = 0; j_2__ < X2_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < X2_j_1_max__; ++j_1__) {
                    X2(j_1__, j_2__) = vals_r__[pos__++];
                }
            }

            current_statement_begin__ = 26;
            validate_non_negative_index("s_theta", "M1", M1);
            context__.validate_dims("data initialization", "s_theta", "double", context__.to_vec(M1));
            s_theta = std::vector<double>(M1, double(0));
            vals_r__ = context__.vals_r("s_theta");
            pos__ = 0;
            size_t s_theta_k_0_max__ = M1;
            for (size_t k_0__ = 0; k_0__ < s_theta_k_0_max__; ++k_0__) {
                s_theta[k_0__] = vals_r__[pos__++];
            }
            size_t s_theta_i_0_max__ = M1;
            for (size_t i_0__ = 0; i_0__ < s_theta_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "s_theta[i_0__]", s_theta[i_0__], 0);
            }

            current_statement_begin__ = 27;
            validate_non_negative_index("s", "M2", M2);
            context__.validate_dims("data initialization", "s", "double", context__.to_vec(M2));
            s = std::vector<double>(M2, double(0));
            vals_r__ = context__.vals_r("s");
            pos__ = 0;
            size_t s_k_0_max__ = M2;
            for (size_t k_0__ = 0; k_0__ < s_k_0_max__; ++k_0__) {
                s[k_0__] = vals_r__[pos__++];
            }
            size_t s_i_0_max__ = M2;
            for (size_t i_0__ = 0; i_0__ < s_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "s[i_0__]", s[i_0__], 0);
            }


            // initialize transformed data variables
            current_statement_begin__ = 31;
            N_ones = int(0);
            stan::math::fill(N_ones, std::numeric_limits<int>::min());
            stan::math::assign(N_ones,num_ones(y, pstream__));

            // execute transformed data statements

            // validate transformed data
            current_statement_begin__ = 31;
            check_greater_or_equal(function__, "N_ones", N_ones, 0);


            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 36;
            validate_non_negative_index("theta", "M1", M1);
            num_params_r__ += M1;
            current_statement_begin__ = 37;
            validate_non_negative_index("beta", "M2", M2);
            num_params_r__ += M2;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_model() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        current_statement_begin__ = 36;
        if (!(context__.contains_r("theta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable theta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("theta");
        pos__ = 0U;
        validate_non_negative_index("theta", "M1", M1);
        context__.validate_dims("parameter initialization", "theta", "vector_d", context__.to_vec(M1));
        Eigen::Matrix<double, Eigen::Dynamic, 1> theta(M1);
        size_t theta_j_1_max__ = M1;
        for (size_t j_1__ = 0; j_1__ < theta_j_1_max__; ++j_1__) {
            theta(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(theta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable theta: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        current_statement_begin__ = 37;
        if (!(context__.contains_r("beta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable beta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("beta");
        pos__ = 0U;
        validate_non_negative_index("beta", "M2", M2);
        context__.validate_dims("parameter initialization", "beta", "vector_d", context__.to_vec(M2));
        Eigen::Matrix<double, Eigen::Dynamic, 1> beta(M2);
        size_t beta_j_1_max__ = M2;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            beta(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(beta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable beta: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);

            // model parameters
            current_statement_begin__ = 36;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> theta;
            (void) theta;  // dummy to suppress unused var warning
            if (jacobian__)
                theta = in__.vector_constrain(M1, lp__);
            else
                theta = in__.vector_constrain(M1);

            current_statement_begin__ = 37;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> beta;
            (void) beta;  // dummy to suppress unused var warning
            if (jacobian__)
                beta = in__.vector_constrain(M2, lp__);
            else
                beta = in__.vector_constrain(M2);

            // transformed parameters
            current_statement_begin__ = 42;
            validate_non_negative_index("eta_theta", "N", N);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> eta_theta(N);
            stan::math::initialize(eta_theta, DUMMY_VAR__);
            stan::math::fill(eta_theta, DUMMY_VAR__);

            current_statement_begin__ = 43;
            validate_non_negative_index("eta_beta", "N", N);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> eta_beta(N);
            stan::math::initialize(eta_beta, DUMMY_VAR__);
            stan::math::fill(eta_beta, DUMMY_VAR__);

            current_statement_begin__ = 44;
            validate_non_negative_index("w", "N", N);
            std::vector<local_scalar_t__> w(N, local_scalar_t__(0));
            stan::math::initialize(w, DUMMY_VAR__);
            stan::math::fill(w, DUMMY_VAR__);

            current_statement_begin__ = 45;
            validate_non_negative_index("p", "N", N);
            std::vector<local_scalar_t__> p(N, local_scalar_t__(0));
            stan::math::initialize(p, DUMMY_VAR__);
            stan::math::fill(p, DUMMY_VAR__);

            // transformed parameters block statements
            current_statement_begin__ = 47;
            stan::math::assign(eta_theta, multiply(X1, theta));
            current_statement_begin__ = 48;
            stan::math::assign(eta_beta, multiply(X2, beta));
            current_statement_begin__ = 50;
            for (int n = 1; n <= N; ++n) {

                current_statement_begin__ = 51;
                stan::model::assign(w, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            (stan::math::exp(get_base1(eta_theta, n, "eta_theta", 1)) / (2 + (2 * stan::math::exp(get_base1(eta_theta, n, "eta_theta", 1))))), 
                            "assigning variable w");
                current_statement_begin__ = 53;
                stan::model::assign(p, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            (0.5 + (stan::math::exp(get_base1(eta_beta, n, "eta_beta", 1)) / (2 + (2 * stan::math::exp(get_base1(eta_beta, n, "eta_beta", 1)))))), 
                            "assigning variable p");
            }

            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            current_statement_begin__ = 42;
            size_t eta_theta_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < eta_theta_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(eta_theta(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: eta_theta" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable eta_theta: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            current_statement_begin__ = 43;
            size_t eta_beta_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < eta_beta_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(eta_beta(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: eta_beta" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable eta_beta: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            current_statement_begin__ = 44;
            size_t w_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < w_k_0_max__; ++k_0__) {
                if (stan::math::is_uninitialized(w[k_0__])) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: w" << "[" << k_0__ << "]";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable w: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            size_t w_i_0_max__ = N;
            for (size_t i_0__ = 0; i_0__ < w_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "w[i_0__]", w[i_0__], 0);
                check_less_or_equal(function__, "w[i_0__]", w[i_0__], 0.5);
            }

            current_statement_begin__ = 45;
            size_t p_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < p_k_0_max__; ++k_0__) {
                if (stan::math::is_uninitialized(p[k_0__])) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: p" << "[" << k_0__ << "]";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable p: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            size_t p_i_0_max__ = N;
            for (size_t i_0__ = 0; i_0__ < p_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "p[i_0__]", p[i_0__], 0.5);
                check_less_or_equal(function__, "p[i_0__]", p[i_0__], 1);
            }


            // model body

            current_statement_begin__ = 59;
            for (int i = 1; i <= M1; ++i) {

                current_statement_begin__ = 60;
                lp_accum__.add(normal_log(get_base1(theta, i, "theta", 1), 0, get_base1(s_theta, i, "s_theta", 1)));
            }
            current_statement_begin__ = 62;
            for (int i = 1; i <= M2; ++i) {

                current_statement_begin__ = 63;
                lp_accum__.add(normal_log(get_base1(beta, i, "beta", 1), 0, get_base1(s, i, "s", 1)));
            }
            current_statement_begin__ = 66;
            for (int n = 1; n <= N; ++n) {

                current_statement_begin__ = 67;
                lp_accum__.add(zib_lpmf(get_base1(y, n, "y", 1), get_base1(w, n, "w", 1), get_base1(p, n, "p", 1), N_ones, N, pstream__));
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("theta");
        names__.push_back("beta");
        names__.push_back("eta_theta");
        names__.push_back("eta_beta");
        names__.push_back("w");
        names__.push_back("p");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(M1);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(M2);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_model_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning

        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> theta = in__.vector_constrain(M1);
        size_t theta_j_1_max__ = M1;
        for (size_t j_1__ = 0; j_1__ < theta_j_1_max__; ++j_1__) {
            vars__.push_back(theta(j_1__));
        }

        Eigen::Matrix<double, Eigen::Dynamic, 1> beta = in__.vector_constrain(M2);
        size_t beta_j_1_max__ = M2;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            vars__.push_back(beta(j_1__));
        }

        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        if (!include_tparams__ && !include_gqs__) return;

        try {
            // declare and define transformed parameters
            current_statement_begin__ = 42;
            validate_non_negative_index("eta_theta", "N", N);
            Eigen::Matrix<double, Eigen::Dynamic, 1> eta_theta(N);
            stan::math::initialize(eta_theta, DUMMY_VAR__);
            stan::math::fill(eta_theta, DUMMY_VAR__);

            current_statement_begin__ = 43;
            validate_non_negative_index("eta_beta", "N", N);
            Eigen::Matrix<double, Eigen::Dynamic, 1> eta_beta(N);
            stan::math::initialize(eta_beta, DUMMY_VAR__);
            stan::math::fill(eta_beta, DUMMY_VAR__);

            current_statement_begin__ = 44;
            validate_non_negative_index("w", "N", N);
            std::vector<double> w(N, double(0));
            stan::math::initialize(w, DUMMY_VAR__);
            stan::math::fill(w, DUMMY_VAR__);

            current_statement_begin__ = 45;
            validate_non_negative_index("p", "N", N);
            std::vector<double> p(N, double(0));
            stan::math::initialize(p, DUMMY_VAR__);
            stan::math::fill(p, DUMMY_VAR__);

            // do transformed parameters statements
            current_statement_begin__ = 47;
            stan::math::assign(eta_theta, multiply(X1, theta));
            current_statement_begin__ = 48;
            stan::math::assign(eta_beta, multiply(X2, beta));
            current_statement_begin__ = 50;
            for (int n = 1; n <= N; ++n) {

                current_statement_begin__ = 51;
                stan::model::assign(w, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            (stan::math::exp(get_base1(eta_theta, n, "eta_theta", 1)) / (2 + (2 * stan::math::exp(get_base1(eta_theta, n, "eta_theta", 1))))), 
                            "assigning variable w");
                current_statement_begin__ = 53;
                stan::model::assign(p, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            (0.5 + (stan::math::exp(get_base1(eta_beta, n, "eta_beta", 1)) / (2 + (2 * stan::math::exp(get_base1(eta_beta, n, "eta_beta", 1)))))), 
                            "assigning variable p");
            }

            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            current_statement_begin__ = 44;
            size_t w_i_0_max__ = N;
            for (size_t i_0__ = 0; i_0__ < w_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "w[i_0__]", w[i_0__], 0);
                check_less_or_equal(function__, "w[i_0__]", w[i_0__], 0.5);
            }

            current_statement_begin__ = 45;
            size_t p_i_0_max__ = N;
            for (size_t i_0__ = 0; i_0__ < p_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "p[i_0__]", p[i_0__], 0.5);
                check_less_or_equal(function__, "p[i_0__]", p[i_0__], 1);
            }

            // write transformed parameters
            if (include_tparams__) {
                size_t eta_theta_j_1_max__ = N;
                for (size_t j_1__ = 0; j_1__ < eta_theta_j_1_max__; ++j_1__) {
                    vars__.push_back(eta_theta(j_1__));
                }
                size_t eta_beta_j_1_max__ = N;
                for (size_t j_1__ = 0; j_1__ < eta_beta_j_1_max__; ++j_1__) {
                    vars__.push_back(eta_beta(j_1__));
                }
                size_t w_k_0_max__ = N;
                for (size_t k_0__ = 0; k_0__ < w_k_0_max__; ++k_0__) {
                    vars__.push_back(w[k_0__]);
                }
                size_t p_k_0_max__ = N;
                for (size_t k_0__ = 0; k_0__ < p_k_0_max__; ++k_0__) {
                    vars__.push_back(p[k_0__]);
                }
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    std::string model_name() const {
        return "model_model";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t theta_j_1_max__ = M1;
        for (size_t j_1__ = 0; j_1__ < theta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "theta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t beta_j_1_max__ = M2;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            size_t eta_theta_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < eta_theta_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "eta_theta" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t eta_beta_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < eta_beta_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "eta_beta" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t w_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < w_k_0_max__; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "w" << '.' << k_0__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t p_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < p_k_0_max__; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "p" << '.' << k_0__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t theta_j_1_max__ = M1;
        for (size_t j_1__ = 0; j_1__ < theta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "theta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t beta_j_1_max__ = M2;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            size_t eta_theta_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < eta_theta_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "eta_theta" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t eta_beta_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < eta_beta_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "eta_beta" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t w_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < w_k_0_max__; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "w" << '.' << k_0__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t p_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < p_k_0_max__; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "p" << '.' << k_0__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }

        if (!include_gqs__) return;
    }

}; // model

}  // namespace

typedef model_model_namespace::model_model stan_model;

#ifndef USING_R

stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}

#endif


#endif
