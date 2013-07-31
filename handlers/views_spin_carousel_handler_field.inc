<?php
// This line is so VIM recognizes this as a PHP file:
// vim:ft=php:shiftwidth=3:tabstop=3:


class views_spin_carousel_handler_field extends views_handler_field_field {

   function options( &$options ) {
      parent::options( $options );

      $options['spin_carousel_flipper'] = array( 'front' );
   }

   function options_form( &$form, &$form_state ) {
      parent::options_form( $form, $form_state );

      //dpm( $this->options );
      //dpm( $form );

      $form['spin_carousel_flipper'] = array(
         '#type' => 'select',
         '#title' => t( 'Carousel flip side' ),
         '#description' => t( 'The side of the flipper on which to appear '.
            'if the 3D carousel view is selected.' ),
         '#options' => array( 'front' => t( 'Front' ), 'back' => t( 'Back' ) ),
         '#default_value' => $this->options['spin_carousel_flipper'],
      );
   }

   function options_submit( &$form, &$form_state ) {
      parent::options_submit( $form, $form_state );

      $this->options['spin_carousel_flipper'] = 
         $form_state['input']['options']['spin_carousel_flipper'];

      //dpm( $form_state );
   }
}

