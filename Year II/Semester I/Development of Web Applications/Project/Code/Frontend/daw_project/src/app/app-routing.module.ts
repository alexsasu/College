import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { AuthGuard } from './guards/auth.guard';

const routes: Routes = [
  {
    path: '',
    loadChildren: () => import('src/app/modules/pc-components/pc-components.module').then(m => m.PcComponentsModule)
  },
  {
    path: 'pc-components',
    loadChildren: () => import('src/app/modules/pc-components/pc-components.module').then(m => m.PcComponentsModule)
  },
  {
    path: 'clients',
    canActivate: [AuthGuard],
    children: [
      {
        path: '',
        loadChildren: () => import('src/app/modules/clients/clients.module').then(m => m.ClientsModule)
      }
    ]
  },
  {
    path: 'employees',
    canActivate: [AuthGuard],
    children: [
      {
        path: '',
        loadChildren: () => import('src/app/modules/employees/employees.module').then(m => m.EmployeesModule)
      }
    ]
  },
  {
    path: 'auth',
    loadChildren: () => import('src/app/modules/authentication/authentication.module').then(m => m.AuthenticationModule)
  },
  {
    path: 'auth',
    loadChildren: () => import('src/app/modules/authentication/authentication.module').then(m => m.AuthenticationModule)
  }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
